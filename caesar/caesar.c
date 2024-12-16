#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int rotate(char c, int key);
bool only_digits(string key);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    if (!only_digits(argv[1]))
    {
        printf("The key should be only digits\n");
        return 1;
    }

    int key = atoi(argv[1]);

    string plain_text = get_string("plaintext:  ");

    for (int i = 0, len = strlen(plain_text); i < len; i++ )
    {
        plain_text[i] = rotate(plain_text[i], key);
    }

    printf("ciphertext: %s\n", plain_text);
}

int rotate(char c, int key)
{
    int gap;
    
    if (islower(c))
    {
        gap = c - 'a';
        gap = (gap + key) % 26;
        c = gap + 'a';
    }
    else if(isupper(c))
    {
        gap = c - 'A';
        gap = (gap + key) % 26;
        c = gap + 'A';
    }
    else {
        gap = c;
    }

    return c;
}

bool only_digits(string key)
{
    for (int i = 0, len = strlen(key); i < len; i++)
    {
        if (!isdigit(key[i]))
        {
            return false;
        }
    }

    return true;
}
