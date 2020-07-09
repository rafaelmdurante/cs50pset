#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <getopt.h>

// block size
#define BLOCK_SIZE 512
// definition of byte (just for practice purposes)
typedef uint8_t BYTE;

int jpgheader(BYTE * buffer);

int main(int argc, char *argv[])
{
    // ensure proper usage
    if (argc != optind + 1)
    {
        fprintf(stderr, "Usage: ./recover <infile.raw>\n");
        return 1;
    }

    // open input file
    FILE *infile = fopen(argv[optind], "r");

    // definition of buffer
    BYTE buffer[BLOCK_SIZE];

    // jpeg counter
    int jpegs = 0;

    // '000.jpg\0' is 8 char long
    char filename[8];

    // open pointer to image
    FILE *image = NULL;

    while (fread(buffer, sizeof(buffer), 1, infile))
    {
        // validate if header is a jpeg file
        if (jpgheader(buffer))
        {
            // if image is not null it means it is not the first
            if (image)
            {
                // close file
                fclose(image);

                // increase counter for next filename
                jpegs++;
            }

            // print string with name of file
            sprintf(filename, "%03i.jpg", jpegs);

            // open file to write
            image = fopen(filename, "w");
        }

        // if image is not null it means it is in the middle of a file
        if (image)
        {
            // write buffer to file
            fwrite(buffer, sizeof(buffer), 1, image);
        }
    }

    // close last file
    fclose(image);

    // return success
    return 0;
}

int jpgheader(BYTE * buffer)
{
    return (buffer[0] == 0xff && buffer[1] == 0xd8
            && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0);
}