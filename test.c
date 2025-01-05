#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct 
{
    int8_t x;
    int8_t y;
} POINT;

uint32_t dict_size;

int main(int argc, char *argv[])
{
   char word2[10];
   char *word = "show";

   if (!strcpy(word2, word))
   {
    printf("not copied\n");
    return 1;
   }

   printf("%s\n", word2);
   printf("%s\n", word);
   printf("%li\n", strlen(word2));
   printf("%li\n", sizeof(word2));
   printf("%i\n", strcmp(word2, "word"));
   printf("%i\n", dict_size);
}