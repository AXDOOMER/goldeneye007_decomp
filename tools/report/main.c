#include <stdio.h>
#include <stdlib.h>
#include "objectives.h"

#define LINE "__________________________________________________________________"

#define PERCENTF(val, val_max) (((float)val / (float)val_max) * 100.f)

void get_total_objectives(int *max_objs)
{
	/************************/
	int tmp_mis = LVL_DAM, tmp_obj = OBJ_A;
	/************************/

	for(;;)
	{
		if(missions[tmp_mis].obj[tmp_obj].line1[0] == '\0') /* reached end of mission's objectives, check next mission */
		{
			if(missions[tmp_mis + 1].obj[OBJ_A].line1[0] == '\0') /* reached end of struct, stop counting */
			{
				break;
			}
			tmp_mis += 1;
			tmp_obj = OBJ_A;
		}
		tmp_obj += 1;
		*max_objs += 1;
	}
}

void cur_mission_and_objective(int *cur_mis, int *cur_obj, int decomp_progress)
{
	/************************/
	int max_objs = 0;
	/************************/

	for(;;)
	{
		if(missions[*cur_mis].obj[*cur_obj].line1[0] == '\0') /* reached end of mission's objectives, check next mission */
		{
			if(missions[*cur_mis + 1].obj[OBJ_A].line1[0] == '\0') /* reached end of struct, stop counting */
			{
				break;
			}
			*cur_mis += 1;
			*cur_obj = OBJ_A;
		}
		if(max_objs > decomp_progress)
		{
			break;
		}
		*cur_obj += 1;
		max_objs += 1;
	}
}

int get_mission_max_objectives(const int cur_mis)
{
	/************************/
	int cur_obj = OBJ_A;
	/************************/

	for(;;)
	{
		if(missions[cur_mis].obj[cur_obj].line1[0] == '\0') /* reached end of mission's objectives, break */
		{
			break;
		}
		cur_obj++;
	}
	return cur_obj;
}

int main(int argc, char **argv)
{
	/************************/
	long int src_dir, src_dir_max;
	long int game_dir, game_dir_max;
	long int inflate_dir, inflate_dir_max;
	long int libultra_dir, libultra_dir_max;
	long int decompiled, decompiled_max;
	int cur_mis = LVL_DAM, cur_obj = OBJ_A;
	int max_mis_objs = 0, max_objs = 0;
	int tmp_obj, cur_line = 0;
	FILE *html;
	/************************/

	printf("\n  GoldenEye 007 Decompiled Statistics Generator\n%s\n", LINE);
	if(argc != 12) /* incorrect number of arguments */
	{
		printf("\n  About: Generate decompiled statistics website\n\n  Syntax: %s src max game max inflate max libultra max all max html\n\n  Note: Each dir's statistic must be followed with the total words for the dir.\n  Example: 1481 15854 12641 232276 564 1312 556 20330 15242 269772 results.html", argv[0]);
		goto exit;
	}

	/* read arguments */
	src_dir = atol(argv[1]), src_dir_max = atol(argv[2]);
	game_dir = atol(argv[3]), game_dir_max = atol(argv[4]);
	inflate_dir = atol(argv[5]), inflate_dir_max = atol(argv[6]);
	libultra_dir = atol(argv[7]), libultra_dir_max = atol(argv[8]);
	decompiled = atol(argv[9]), decompiled_max = atol(argv[10]);
	if(src_dir_max < src_dir)
	{
		printf("\n  Error: Aborted, src larger than src max argument");
		goto exit;
	}
	if(game_dir_max < game_dir)
	{
		printf("\n  Error: Aborted, game larger than game max argument");
		goto exit;
	}
	if(inflate_dir_max < inflate_dir)
	{
		printf("\n  Error: Aborted, inflate larger than inflate max argument");
		goto exit;
	}
	if(libultra_dir_max < libultra_dir)
	{
		printf("\n  Error: Aborted, libultra larger than libultra max argument");
		goto exit;
	}
	if(decompiled_max < decompiled)
	{
		printf("\n  Error: Aborted, decompiled larger than decompiled max argument");
		goto exit;
	}

	html = fopen(argv[11], "ab");
	if(html == NULL)
	{
		printf("\n  Error: Aborted, %s cannot be opened", argv[11]);
		goto exit;
	}

	get_total_objectives(&max_objs);
	cur_mission_and_objective(&cur_mis, &cur_obj, (int)(((float)decompiled / (float)decompiled_max) * (float)max_objs));
	max_mis_objs = get_mission_max_objectives(cur_mis);

	fprintf(html, "<text x=\"363\" y=\"648\">%s</text>", missions[cur_mis].diff);
	fprintf(html, "<text x=\"363\" y=\"754\">%s</text>", missions[cur_mis].title);
	fprintf(html, "<text x=\"363\" y=\"858\">%s</text>", missions[cur_mis].part);
	fprintf(html, "<text x=\"363\" y=\"1015\">REPORT:</text>");
	fprintf(html, "<text x=\"363\" y=\"1173\">Mission status:</text>");
	fprintf(html, "<text x=\"1004\" y=\"1173\"%s</text>", cur_obj == max_mis_objs ? ">Completed" : " class=\"failed\">FAILED");

	for(tmp_obj = OBJ_A; tmp_obj < max_mis_objs; tmp_obj++)
	{
		fprintf(html, "<text x=\"363\" y=\"%d\">%s</text>", line_rows[cur_line], diff_char[tmp_obj]);
		fprintf(html, "<text x=\"493\" y=\"%d\">%s</text>", line_rows[cur_line], missions[cur_mis].obj[tmp_obj].line1);
		fprintf(html, "<text x=\"562\" y=\"%d\">%s</text>", line_rows[cur_line+1], missions[cur_mis].obj[tmp_obj].line2);
		fprintf(html, "<text x=\"2032\" y=\"%d\"%s</text>", line_rows[cur_line], tmp_obj < cur_obj ? ">Completed" : " class=\"failed\">FAILED");
		cur_line++;
		if(missions[cur_mis].obj[tmp_obj].line2[0] != '\0') /* if objective took up two lines, skip an extra line for next objective */
		{
			cur_line++;
		}
	}

	fprintf(html, "<a onclick=\"swap_pages()\"><rect x=\"2573\" y=\"945\" height=\"434\" width=\"79\" class=\"button\"></rect></a>");
	fprintf(html, "</svg>");
	fprintf(html, "<svg viewBox=\"0 0 2880 2160\" class=\"stats\" id=\"page2\" style=\"display: none;\">");
	fprintf(html, "<text x=\"363\" y=\"648\">%s</text>", missions[cur_mis].diff);
	fprintf(html, "<text x=\"363\" y=\"754\">%s</text>", missions[cur_mis].title);
	fprintf(html, "<text x=\"363\" y=\"858\">%s</text>", missions[cur_mis].part);
	fprintf(html, "<text x=\"363\" y=\"1015\">STATISTICS:</text>");
	fprintf(html, "<text x=\"363\" y=\"1172\">Time:</text>");
	fprintf(html, "<text x=\"856\" y=\"1172\">00:02</text>");
	fprintf(html, "<text x=\"363\" y=\"1284\">Target:</text>");
	fprintf(html, "<text x=\"856\" y=\"1284\">04:00</text>");
	fprintf(html, "<text x=\"1250\" y=\"1284\">(Best Time: 00:10)</text>");
	fprintf(html, "<text x=\"363\" y=\"1416\">Decomp:</text>\n");
	fprintf(html, "<text x=\"856\" y=\"1416\">%0.1f%%</text>\n", PERCENTF(decompiled, decompiled_max));
	fprintf(html, "<text x=\"363\" y=\"1520\">Weapon of choice:</text>\n");
	fprintf(html, "<text x=\"1246\" y=\"1520\">PP7 (silenced)</text>\n");
	fprintf(html, "<text x=\"363\" y=\"1678\">Shot total:</text>\n");
	fprintf(html, "<text x=\"856\" y=\"1678\">0</text>\n");
	fprintf(html, "<text x=\"363\" y=\"1776\">Kill total:</text>\n");
	fprintf(html, "<text x=\"856\" y=\"1776\">0</text>\n");
	fprintf(html, "<text x=\"1180\" y=\"1678\">src:</text>\n");
	fprintf(html, "<text x=\"1800\" y=\"1678\">%ld (%0.1f%%)</text>\n", src_dir, PERCENTF(src_dir, src_dir_max));
	fprintf(html, "<text x=\"1180\" y=\"1776\">src/game:</text>\n");
	fprintf(html, "<text x=\"1800\" y=\"1776\">%ld (%0.1f%%)</text>\n", game_dir, PERCENTF(game_dir, game_dir_max));
	fprintf(html, "<text x=\"1180\" y=\"1875\">src/inflate:</text>\n");
	fprintf(html, "<text x=\"1800\" y=\"1875\">%ld (%0.1f%%)</text>\n", inflate_dir, PERCENTF(inflate_dir, inflate_dir_max));
	fprintf(html, "<text x=\"1180\" y=\"1973\">src/libultra:</text>\n");
	fprintf(html, "<text x=\"1800\" y=\"1973\">%ld (%0.1f%%)</text>\n", libultra_dir, PERCENTF(libultra_dir, libultra_dir_max));
	fprintf(html, "<a onclick=\"swap_pages()\"><rect x=\"2573\" y=\"1548\" height=\"434\" width=\"79\" class=\"button\"></rect></a>\n");
	fprintf(html, "</svg>\n");
	fprintf(html, "</div>\n");
	fprintf(html, "</body>\n");
	fprintf(html, "</html>");
	fclose(html);

	printf("\n  Successfully written stats to %s\n", argv[11]);
	printf("\n    %s\n    %s\n\n", missions[cur_mis].diff, missions[cur_mis].part);
	for(tmp_obj = OBJ_A; tmp_obj < max_mis_objs; tmp_obj++)
	{
		printf("      [%s] %s%s\n", tmp_obj < cur_obj ? "X" : " ", missions[cur_mis].obj[tmp_obj].line1, missions[cur_mis].obj[tmp_obj].line2);
	}
	printf("\n    Status: %s\n", cur_obj == max_mis_objs ? "Completed" : "FAILED");

exit:
	printf("\n%s\n\n", LINE);
	return 0;
}
