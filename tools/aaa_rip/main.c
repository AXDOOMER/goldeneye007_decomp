#include <stdio.h>
#include <stdlib.h>

#define LINE "__________________________________________________________________"

int main(int argc, char **argv)
{
	/************************/
	FILE *input, *output;
	long int filesize;
	int offset, length;
	unsigned char *in_buf;
	/************************/

	printf("AAA RIP\n%s\n", LINE);
	if(argc != 5) /* no file provided or too many arguments */
	{
		printf("\n  About: Extract sub-binary from binary\n\n  Syntax: %s \"input file\" \"output file\" \"offset (dec)\" \"length (dec)\"\n  Note: Set length to 0 to write until end of input file\n", argv[0]);
		goto exit;
	}

	/* load input from argument */
	input = fopen(argv[1], "rb");
	if(input == NULL)
	{
		printf("\n  Error: Aborted, input cannot be opened");
		goto exit;
	}
	if(fseek(input, 0, SEEK_END) != 0)
	{
		printf("\n  Error: Aborted, could not find end to input file");
		goto error_input;
	}

	/* load length/offset arguments */
	offset = atoi(argv[3]);
	length = atoi(argv[4]);
	if(offset < 0)
	{
		printf("\n  Error: Aborted, invalid offset argument");
		goto error_input;
	}

	/* get input filesize */
	filesize = ftell(input);
	if(filesize == -1)
	{
		printf("\n  Error: Aborted, could not find length of input file");
		goto error_input;
	}
	if(fseek(input, offset, SEEK_SET) != 0)
	{
		printf("\n  Error: Aborted, could not set offset position");
		goto error_input;
	}
	if(length <= 0)
	{
		length = filesize - offset;
	}
	if(offset + length > filesize)
	{
		printf("\n  Error: Aborted, length goes beyond end of file");
		goto error_input;
	}
	printf("\n  Input File: %s\n", argv[1]);

	/* read input to file buffer */
	in_buf = (unsigned char *)malloc(length);
	if(in_buf == NULL)
	{
		printf("\n  Error: Aborted, not enough memory to load input");
		goto error_input;
	}
	filesize = fread(in_buf, length, 1, input);

	/* open output file */
	output = fopen(argv[2], "wb");
	if(input == NULL)
	{
		printf("\n  Error: Aborted, output file cannot be written");
		goto error_output;
	}
	fwrite(in_buf, length, 1, output);

	fclose(output);
error_output:
	free(in_buf);
error_input:
	fclose(input);
exit:
	printf("\n%s\n", LINE);
	return 0;
}