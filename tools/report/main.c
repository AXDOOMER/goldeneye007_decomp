#include <stdio.h>
#include <stdlib.h>
#include "objectives.h"

#define LINE "__________________________________________________________________"

#define PERCENTF(val, val_max) (((float)val / (float)val_max) * 100.f)

int total_objectives(void)
{
	/************************/
	int tmp_mis = 0;
	int tmp_obj = OBJ_A;
	int max_objs = 0;
	/************************/

	for(;;)
	{
		if(missions[tmp_mis].obj[tmp_obj].line1[0] == '\0') /* reached end of mission's objectives, check next mission */
		{
			if(missions[tmp_mis + 1].obj[OBJ_A].line1[0] == '\0') /* reached end of struct, stop counting */
			{
				break;
			}
			tmp_mis++;
			tmp_obj = OBJ_A;
		}
		tmp_obj++;
		max_objs++;
	}
	return max_objs;
}

void calc_mission_and_objective(int *cur_mis, int *cur_obj, int decomp_progress)
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
		*cur_obj += 1;
		max_objs += 1;
		if(max_objs >= decomp_progress)
		{
			break;
		}
	}
}

int max_objectives(const int cur_mis)
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
	long int decompiled_words, decompiled_words_max;
	long int decompiled_files, decompiled_files_max;
	int cur_mis = 0, cur_obj = OBJ_A;
	int cur_mis_objs_max = 0, max_objs = 0;
	int tmp_obj, cur_line = 0;
	int last_modified_file_arg_active = 0;
	float total_complete, obj_remaining;
	FILE *html;
	/************************/

	printf("\n  GoldenEye 007 Decompiled Statistics Generator\n%s\n", LINE);
	if((argc != 14) && (argc != 15)) /* incorrect number of arguments */
	{
		printf("\n  About: Generate decompiled statistics website\n\n  Syntax: %s src max game max inflate max libultra max decompiled_words max_words decompiled_files all_files html_output last_modified_file\n\n  Note: Each dir's statistic must be followed with the total words for the dir.\n  Example: 1481 15854 12641 232276 564 1312 556 20330 15242 269772 49 336 ./results.html \"src/game/bond.c\"", argv[0]);
		goto exit;
	}

	/* read arguments */
	src_dir = atol(argv[1]), src_dir_max = atol(argv[2]);
	game_dir = atol(argv[3]), game_dir_max = atol(argv[4]);
	inflate_dir = atol(argv[5]), inflate_dir_max = atol(argv[6]);
	libultra_dir = atol(argv[7]), libultra_dir_max = atol(argv[8]);
	decompiled_words = atol(argv[9]), decompiled_words_max = atol(argv[10]);
	decompiled_files = atol(argv[11]), decompiled_files_max = atol(argv[12]);
	if(src_dir > src_dir_max)
	{
		printf("\n  Error: Aborted, src larger than src max argument");
		goto exit;
	}
	if(game_dir > game_dir_max)
	{
		printf("\n  Error: Aborted, game larger than game max argument");
		goto exit;
	}
	if(inflate_dir > inflate_dir_max)
	{
		printf("\n  Error: Aborted, inflate larger than inflate max argument");
		goto exit;
	}
	if(libultra_dir > libultra_dir_max)
	{
		printf("\n  Error: Aborted, libultra larger than libultra max argument");
		goto exit;
	}
	if(decompiled_words > decompiled_words_max)
	{
		printf("\n  Error: Aborted, decompiled words larger than total words argument");
		goto exit;
	}
	if(decompiled_files > decompiled_files_max)
	{
		printf("\n  Error: Aborted, decompiled files larger than total files argument");
		goto exit;
	}
	if(src_dir < 0 || src_dir_max < 0 || game_dir < 0 || game_dir_max < 0 || inflate_dir < 0 || inflate_dir_max < 0 || libultra_dir < 0 || libultra_dir_max < 0 || decompiled_words < 0 || decompiled_words_max < 0|| decompiled_files < 0 || decompiled_files_max < 0)
	{
		printf("\n  Error: Aborted, detected negative arguments (invalid or overflow)");
		goto exit;
	}
	if(argc == 15)
	{
		last_modified_file_arg_active = (argv[14] != NULL);
	}

	html = fopen(argv[13], "ab");
	if(html == NULL)
	{
		printf("\n  Error: Aborted, %s cannot be opened", argv[13]);
		goto exit;
	}

	max_objs = total_objectives();
	total_complete = ((float)decompiled_words / (float)decompiled_words_max) * (float)max_objs;
	obj_remaining = total_complete - (float)((int)total_complete);
	calc_mission_and_objective(&cur_mis, &cur_obj, (int)total_complete);
	cur_mis_objs_max = max_objectives(cur_mis);

	fprintf(html, "<text x=\"363\" y=\"648\">%s: James Bond</text>\n", missions[cur_mis].diff);
	fprintf(html, "<text x=\"363\" y=\"754\">Mission %s: %s</text>\n", missions[cur_mis].title_num, missions[cur_mis].title_name);
	fprintf(html, "<text x=\"363\" y=\"858\">%s: %s</text>\n", missions[cur_mis].part_num, missions[cur_mis].part_name);
	fprintf(html, "<text x=\"363\" y=\"1015\">REPORT:</text>\n");
	fprintf(html, "<text x=\"363\" y=\"1173\">Mission status:</text>\n");
	fprintf(html, "<text x=\"1004\" y=\"1173\"%s</text>\n", cur_obj == cur_mis_objs_max ? ">Completed" : " class=\"failed\">FAILED");

	for(tmp_obj = OBJ_A; tmp_obj < cur_mis_objs_max; tmp_obj++, cur_line++)
	{
		fprintf(html, "<text x=\"363\" y=\"%d\">%s</text>\n", line_rows[cur_line], diff_char[tmp_obj]);
		fprintf(html, "<text x=\"493\" y=\"%d\">%s</text>\n", line_rows[cur_line], missions[cur_mis].obj[tmp_obj].line1);
		fprintf(html, "<text x=\"562\" y=\"%d\">%s</text>\n", line_rows[cur_line+1], missions[cur_mis].obj[tmp_obj].line2);
		fprintf(html, "<text x=\"2032\" y=\"%d\"%s</text>\n", line_rows[cur_line], tmp_obj < cur_obj ? ">Completed" : " class=\"failed\">FAILED");
		if(missions[cur_mis].obj[tmp_obj].line2[0] != '\0') /* if objective took up two lines, skip an extra line for next objective */
		{
			cur_line++;
		}
	}

	fprintf(html, "<a onclick=\"swap_pages()\"><rect x=\"2573\" y=\"945\" height=\"434\" width=\"79\" class=\"button\"></rect></a>\n");
	fprintf(html, "</svg>\n");
	fprintf(html, "<svg viewBox=\"0 0 2880 2160\" class=\"stats\" id=\"page2\" style=\"display: none;\">\n");
	fprintf(html, "<text x=\"363\" y=\"648\">%s: James Bond</text>\n", missions[cur_mis].diff);
	fprintf(html, "<text x=\"363\" y=\"754\">Mission %s: %s</text>\n", missions[cur_mis].title_num, missions[cur_mis].title_name);
	fprintf(html, "<text x=\"363\" y=\"858\">%s: %s</text>\n", missions[cur_mis].part_num, missions[cur_mis].part_name);
	fprintf(html, "<text x=\"363\" y=\"1015\">STATISTICS:</text>\n");
	fprintf(html, "<text x=\"363\" y=\"1172\">Time:</text>\n");
	fprintf(html, "<text x=\"856\" y=\"1172\">00:02</text>\n");
	fprintf(html, "<text x=\"363\" y=\"1284\">Target:</text>\n");
	fprintf(html, "<text x=\"856\" y=\"1284\">04:00</text>\n");
	fprintf(html, "<text x=\"1250\" y=\"1284\">(Best Time: 00:10)</text>\n");
	fprintf(html, "<text x=\"363\" y=\"1416\">Decomp:</text>\n");
	fprintf(html, "<text x=\"856\" y=\"1416\">%0.1f%%</text>\n", PERCENTF(decompiled_words, decompiled_words_max));
	if(last_modified_file_arg_active)
	{
		fprintf(html, "<text x=\"363\" y=\"1520\">Last modified file:</text>\n");
		fprintf(html, "<text x=\"1180\" y=\"1520\">%s</text>\n", argv[14]);
	}
	else
	{
		fprintf(html, "<text x=\"363\" y=\"1520\">Weapon of choice:</text>\n");
		fprintf(html, "<text x=\"1246\" y=\"1520\">PP7 (silenced)</text>\n");
	}
	fprintf(html, "<text x=\"363\" y=\"1678\">Files done:</text>\n");
	fprintf(html, "<text x=\"856\" y=\"1678\">%ld</text>\n", decompiled_files);
	fprintf(html, "<text x=\"363\" y=\"1776\">Files total:</text>\n");
	fprintf(html, "<text x=\"856\" y=\"1776\">%ld</text>\n", decompiled_files_max);
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

	printf("\n  Successfully written stats to %s\n", argv[13]);
	printf("\n    %s: %s (%s)\n", missions[cur_mis].title_name, missions[cur_mis].part_name, missions[cur_mis].diff);
	for(tmp_obj = OBJ_A; tmp_obj < cur_mis_objs_max; tmp_obj++)
	{
		printf("\n      [%s] %s", tmp_obj < cur_obj ? "X" : " ", missions[cur_mis].obj[tmp_obj].line1);
		if(missions[cur_mis].obj[tmp_obj].line2[0] != '\0')
			printf(" %s", missions[cur_mis].obj[tmp_obj].line2);
		if(tmp_obj == cur_obj)
			printf(" - %0.1f%%", obj_remaining * 100.f);
	}
	if(total_complete == max_objs)
		printf("\n\n    Mission Status: Completed\n\n    Baron has been defeated - decomp is complete!!");
	else
		printf("\n\n    Mission Status: %s", cur_obj == cur_mis_objs_max ? "Completed" : "FAILED");

exit:
	printf("\n%s\n\n", LINE);
	return 0;
}
