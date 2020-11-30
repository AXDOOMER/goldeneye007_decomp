#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

#define LINE "__________________________________________________________________"

int main(int argc, char **argv)
{
	/************************/
	FILE *input, *output;
	long int filesize;
	int offset, length, offset_output;
	unsigned char *in_buf, *out_buf;
	/************************/

	printf("\n  AAA RIP - Lite DD Clone\n%s\n", LINE);
	if((argc != 5) && (argc != 6)) /* no file provided or too many arguments */
	{
		printf("\n  About: Extract sub-binary from binary\n\n  Syntax: %s \"in\" \"out\" \"offset\" \"length\" \"out offset\"\n\n  Notes:\n  Setting length argument to 0 will write until end of input file.\n  All arguments assume decimal value.\n  Omitting output offset will overwrite output file.", argv[0]);
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
	offset_output = (argc == 6) ? atoi(argv[5]) : 0;
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
	if(offset >= filesize)
	{
		printf("\n  Error: Aborted, offset goes beyond end of file");
		goto error_input;
	}
	if(offset + length > filesize)
	{
		printf("\n  Error: Aborted, length goes beyond end of file");
		goto error_input;
	}
	printf("\n  Input File: %s\n  Offset: %d\n  Length: %d", argv[1], offset, length);
	if(argc == 6)
		printf("\n  Output Offset: %d", offset_output);

	/* read input to file buffer */
	in_buf = (unsigned char *)malloc(length);
	if(in_buf == NULL)
	{
		printf("\n  Error: Aborted, not enough memory to load input");
		goto error_input;
	}
	fread(in_buf, length, 1, input);

	/* open output file */
	if(argc == 6)
	{
		output = fopen(argv[2], "rb");
		if(output == NULL)
		{
			printf("\n  Error: Aborted, output file cannot be written");
			goto error_output;
		}
		if(fseek(output, 0, SEEK_END) != 0)
		{
			printf("\n  Error: Aborted, could not find end to output file");
			goto error_offset_output;
		}
		filesize = ftell(output);
		if(fseek(output, 0, SEEK_SET) != 0)
		{
			printf("\n  Error: Aborted, could not set offset position");
			goto error_offset_output;
		}
		if(filesize == -1)
		{
			printf("\n  Error: Aborted, could not find length of output file");
			goto error_offset_output;
		}
		if(filesize < offset_output + offset + length)
		{
			filesize = offset_output + offset + length;
		}

		/* read output file to buffer */
		out_buf = (unsigned char *)calloc(filesize, 1);
		if(out_buf == NULL)
		{
			printf("\n  Error: Aborted, not enough memory to load output");
			goto error_offset_output;
		}
		fread(out_buf, filesize, 1, output);
		memcpy(&out_buf[offset_output], &in_buf[offset], length);
		fclose(output);

		output = fopen(argv[2], "wb");
		if(output == NULL)
		{
			printf("\n  Error: Aborted, output file cannot be written");
			free(out_buf);
			goto error_output;
		}
		fwrite(out_buf, filesize, 1, output);
		free(out_buf);
	}
	else
	{	
		output = fopen(argv[2], "wb");
		if(output == NULL)
		{
			printf("\n  Error: Aborted, output file cannot be written");
			goto error_output;
		}
		fwrite(in_buf, length, 1, output);
	}

error_offset_output:
	fclose(output);
error_output:
	free(in_buf);
error_input:
	fclose(input);
exit:
	printf("\n%s\n", LINE);
	return 0;
}
