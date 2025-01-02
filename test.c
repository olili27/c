#include <math.h>
#include <stdio.h>
#include <stdint.h>

typedef struct 
{
    int8_t x;
    int8_t y;
} POINT;

int main(void)
{
    uint16_t age = 25;
    uint8_t age2 = 199;
    char buffer[8];

    sprintf(buffer, "%03i.jpg", age);
    printf("%s\n", buffer);
    sprintf(buffer, "%03i.jpg", age2);
    printf("%s\n", buffer);
}