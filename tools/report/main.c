#include <stdio.h>
#include <stdlib.h>

#define LINE "__________________________________________________________________"

#define PERCENTF(val, val_max) (((float)val / (float)val_max) * 100.f)

int main(int argc, char **argv)
{
	/************************/
	long int src_dir, src_dir_max;
	long int game_dir, game_dir_max;
	long int inflate_dir, inflate_dir_max;
	long int libultra_dir, libultra_dir_max;
	long int decompiled, decompiled_max;
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
	printf("\n  Successfully written stats to %s", argv[11]);

exit:
	printf("\n%s\n\n", LINE);
	return 0;
}
