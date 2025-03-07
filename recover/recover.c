#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    // Accept a single command-line argument
    if (argc != 2)
    {
        printf("Usage: ./recover FILE\n");
        return 1;
    }

    // Open the memory card
    FILE *card = fopen(argv[1], "r");
    if (card == NULL)
    {
        fclose(card);
        printf("Could not open %s.\n", argv[1]);
        return 1;
    }

    // Create a buffer for a block of data
    uint8_t buffer[512];
    bool found_jpeg = false;
    uint16_t file_counter = 0;

    FILE *writer = NULL;
    char filename[8];

    // While there's still data left to read from the memory card
    while (fread(buffer, 1, 512, card) == 512)
    {
        // check if block is a start of a new jpeg
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff &&
            (buffer[3] & 0xf0) == 0xe0)
        {
            if (writer != NULL)
            {
                fclose(writer);
                writer = NULL;
            }

            sprintf(filename, "%03i.jpg", file_counter);
            file_counter++;

            FILE *file_writer = fopen(filename, "w");
            if (file_writer == NULL)
            {
                printf("Could not create %s.\n", filename);
                return 1;
            }

            writer = file_writer;
            fwrite(buffer, 1, 512, writer);
        }
        else
        {
            // if already found a jpeg
            if (writer != NULL)
            {
                fwrite(buffer, 1, 512, writer);
            }
        }
    }

    fclose(writer);
    fclose(card);
    return 0;
}
