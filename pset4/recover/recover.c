// Program for recovering jpg files from memory

#include <stdio.h>
#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

typedef uint8_t BYTE;

typedef struct
{
	BYTE bytes[512];
}
BLOCK;

int main(int argc, char *argv[])
{
	// ensure proper usage
	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s filename\n", argv[0]);
		return 1;
	}

	// remember file name
	char *filename = argv[1];

	// open file
	FILE *inptr = fopen(filename, "r");
	if (inptr == NULL)
	{
		fprintf(stderr, "Could not open %s.\n", filename);
		return 2;
	}

	char *outfile = malloc(10 * sizeof(char));
	int j = 0;
	int jpg_open = 0;

	BLOCK buffer;

	sprintf(outfile, "%03i.jpg", j);
	FILE *img = fopen(outfile, "w");

	while (fread(&buffer.bytes, sizeof(BYTE), 512, inptr) == 512)
	{
		if(buffer.bytes[0] == 0xff &&
		   buffer.bytes[1] == 0xd8 &&
	 	   buffer.bytes[2] == 0xff &&
		   ((buffer.bytes[3] & 0xf0) == 0xe0))
		{
			if (!jpg_open)
			{
				jpg_open = 1;
				fwrite(&buffer, sizeof(buffer.bytes), 1, img);
			}
			else
			{
				memset(outfile, '\0', 10);
				sprintf(outfile, "%03i.jpg", ++j);
				fclose(img);
				*img = *fopen(outfile, "w");
				fwrite(&buffer, sizeof(buffer.bytes), 1, img);
			}
		}
		else
		{
			if (jpg_open)
			{
				fwrite(&buffer, sizeof(buffer.bytes), 1, img);
			}
		}
	}
	fclose(inptr);
	free(outfile);
	return 0;
}
