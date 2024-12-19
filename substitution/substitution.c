#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

bool only_alpha_characters(string key);
bool contains_repeated_alpha_characters(string key);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    // get the key
    string key = argv[1];

    // validate the key
    // - the key length
    if (strlen(key) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    // - check for non alpha characters
    if (!only_alpha_characters(key)) 
    {
        printf("Key must contain only alphabetic characters\n");
        return 1;
    }
        
    // - check for repeated characters(case insensitive)
    if (contains_repeated_alpha_characters(key))
    {
        printf("Key must not contain repeated characters\n");
        return 1;
    }

    // get the plaintext
    string plaintext = get_string("plaintext: ");

    // encipher
    for (int i = 0, len = strlen(plaintext); i < len; i++) 
    {
        char c = plaintext[i];

        // - leave non alpha characters as-is
        if (isalpha(c))
        {
            int index = tolower(c) - 'a';
            
            // determine what letter it maps to
            char letter_mapped_to = key[index];

            // - preserve the case
            if (isupper(c))
            {
                plaintext[i] = toupper(letter_mapped_to);
            }
            else
            {
                plaintext[i] = tolower(letter_mapped_to);
            }
        }
    }

    // print ciphertext
    printf("ciphertext: %s\n", plaintext);
    return 0;
}

bool only_alpha_characters(string key)
{
    for (int i = 0; i < 26; i++)
    {
        if (!isalpha(key[i]))
        {
            return false;
        }
    }

    return true;
}

bool contains_repeated_alpha_characters(string key)
{
    int count[26] = {0};

    for (int i = 0; i < 26; i++)
    {
        int value = tolower(key[i]) - 'a';
        count[value]++;

        if (count[value] > 1)
        {
            return true;
        }
    }

    return false;
}