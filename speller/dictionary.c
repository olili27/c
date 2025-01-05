// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include "dictionary.h"

#define APOSTROPHE 26

uint32_t dict_size;

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// TODO: Choose number of buckets in hash table
const unsigned int N = APOSTROPHE + 1;

// Hash table
node *table[N];

void free_memory(node *list);

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    node *list = table[hash(word)];

    while (list != NULL)
    {
        if (strcasecmp(list->word, word) == 0)
        {
            return true;
        }

        list = list->next;
    }
    
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    uint16_t sum = 0;

    for (int i = 0, len = strlen(word); i < len; i++)
    {
        uint8_t val = tolower(word[i]) - 'a';
        if (val == 198)
        {
            val = APOSTROPHE;
        }

        sum += val;
    }

    return sum % N;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    dict_size = 0;

    // Open the dictionary file
    FILE *source = fopen(dictionary, "r");
    if (source == NULL)
    {
        return false;
    }

    // Read each word in the file
    char *word;
    node *list;

    while (fscanf(source, "%ms", &word) != EOF)
    {
        uint8_t index = hash(word);
        list = table[index];

        node *new_node = malloc(sizeof(node));
        if (new_node == NULL)
        {
            dict_size = 0;
            return false;
        }

        // Add each word to the hash table
        if (!strcpy(new_node->word, word))
        {
            dict_size = 0;
            return false;
        }

        if (list != NULL)
        {
            new_node->next = list;
        }

        list = new_node;
        dict_size++;
        
        table[index] = list;
    }

    // Close the dictionary file
    fclose(source);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return dict_size;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    for (int i = 0; i < N; i++)
    {
        node *list = table[i];
        node *cursor = list;
        node *tmp = list;

        while (cursor != NULL)
        {
            cursor = cursor->next;
            free(tmp);
            tmp = cursor;
        }
    }

    return true;
}

void free_memory(node *list)
{
    node *tmp;
    node *cursor = list;

    while (cursor != NULL)
    {
        tmp = cursor->next;
        free(cursor);
        cursor = tmp;
    }
}
