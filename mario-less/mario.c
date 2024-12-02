#include <stdio.h>
#include <cs50.h>

int n;

int main(void)
{

    while (n < 1)
    {
        n = get_int("Height: ");
    }

    for (int i = 0; i < n; i++)
    {
        int items = i + 1;
        int spaces = n - items;

        for (int s = 0; s < spaces; s++)
        {
            printf(" ");
        }

        for (int j = 0; j < items; j++)
        {
            printf("#");
        }

        printf("\n");
    }
}
