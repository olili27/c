#include <stdio.h>
#include <cs50.h>

int cash_owed;

int main(void)
{
    while (cash_owed < 1)
    {
        cash_owed = get_int("Cash owed: ");
    }

    int coins = 0;

    while (cash_owed)
    {
        if (cash_owed >= 25)
        {
            cash_owed -= 25;
        }
        else if (cash_owed >= 10)
        {
            cash_owed -= 10;
        }
        else if (cash_owed >= 5)
        {
            cash_owed -= 5;
        }
        else
        {
            cash_owed -= 1;
        }

        coins++;
    }

    printf("%i\n", coins);
}
