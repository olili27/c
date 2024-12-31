#include <math.h>
#include <stdio.h>

typedef struct 
{
    int x;
    int y;
} POINT;

int main(void)
{
    printf("%f\n", roundf(2.54534543));
    printf("%i\n", (int) roundf(2.54534543));
}