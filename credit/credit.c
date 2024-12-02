#include <stdio.h>
#include <cs50.h>
#include <string.h>

int is_even_f(int number);
int number_of_digits(int number);

int main(void)
{
    string number = get_string("Number: ");
    int len = strlen(number);
    int is_even = is_even_f(len);

    int sum = 0;

    if (is_even)
    {
        for (int i = 0; i < len; i++)
        {
            int digit = number[i] - '0';

            if (is_even_f(i))
            {
                digit *= 2;

                int numberOfDig = number_of_digits(digit);
                int str[numberOfDig];

                for (int x = 0; x < numberOfDig; x++)
                {
                    str[x] = digit % 10;
                    digit /= 10;
                }

                for (int n = 0; n < numberOfDig; n++)
                {
                    sum += str[n];
                }
            }
            else
            {
                sum += digit;
            }
        }
    }
    else
    {
        for (int i = 0; i < len; i++)
        {
            int digit = number[i] - '0';

            if (is_even_f(i))
            {
                sum += digit;
            }
            else
            {
                digit *= 2;

                int numberOfDig = number_of_digits(digit);
                int str[numberOfDig];

                for (int x = 0; x < numberOfDig; x++)
                {
                    str[x] = digit % 10;
                    digit /= 10;
                }

                for (int n = 0; n < numberOfDig; n++)
                {
                    sum += str[n];
                }
            }
        }
    }

    if (sum % 10)
    {
        printf("INVALID\n");
    }
    else
    {
        if (len == 15 && (number[0] == '3' && (number[1] == '4' || number[1] == '7')))
        {
            printf("AMEX\n");
        }
        else if (len == 16 && (number[0] == '5' && (number[1] == '1' || number[1] == '2' || number[1] == '3' || number[1] == '4' || number[1] == '5')))
        {
            printf("MASTERCARD\n");
        }
        else if ((len == 16 || len == 13) && number[0] == '4')
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
}

int is_even_f(int number)
{
    return number % 2 == 0;
}

int number_of_digits(int number)
{
    if (!number)
    {
        return 1;
    }

    int length = 0;

    while (number)
    {
        length++;
        number /= 10;
    }

    return length;
}
