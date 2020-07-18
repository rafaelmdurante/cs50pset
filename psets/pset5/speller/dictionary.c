// Implements a dictionary's functionality

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>
// to use tolower()
#include <ctype.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
// ORIGINAL : const unsigned int BUCKETS = 1;
const unsigned int BUCKETS = 10;

// Hash table
node *table[BUCKETS] = {NULL};

// Word counter
unsigned int word_counter = 0;

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    // hashes word to obatin a hash value
    unsigned int position = hash(word);

    // access linked list at the index in the hash table
    node *cursor = table[position];

    // traverse linked list, looking for the word by using a cursor
    while (cursor != NULL)
    {
        /* strcasecmp() shall return an integer greater than, equal to, or less 
           than 0, if the string pointed to by s1 is, ignoring case, greater than,
           equal to, or less than the string pointed to by s2, respectively. */
        if (strcasecmp(cursor->word,word) == 0)
            return true;

        // if it hasn't found the word yet, move to next
        cursor = cursor->next;
    }

    // return false if all no word is found
    return false;
}

// djb2 from http://www.cse.yorku.ca/~oz/hash.html
// Hashes word to a number
unsigned int hash(const char *word)
{
    unsigned long hash = 5381;
    int c;

    /* hash * 33 + c */
    /* hash << 5 shifts the bits to the left */
    // read more: https://stackoverflow.com/questions/8438349/what-does-mean-in-c
    // https://www.codeproject.com/Articles/13740/The-Beginner-s-Guide-to-Using-Enum-Flags
    // convert char to lowercase to make function case insensitive
    while ((c = *word++))
        hash = ((hash << 5) + hash) + tolower(c);

    return hash % BUCKETS;
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    // opens dictionary
    FILE* file = fopen(dictionary, "r");
    if (file == NULL)
        return false;

    // saves words to a hash table
    char word[LENGTH + 1];
    while(fscanf(file, "%s", word) != EOF)
    {
        // create a new node for each word
        node* new_node = malloc(sizeof(node));
        if (new_node == NULL)
            return false;

        // copy word into node
        strcpy(new_node->word, word);

        // get a position in the table
        unsigned int position = hash(word);

        // new node points to the same as the table[position]
        new_node->next = table[position];
        // then table position points to new node
        table[position] = new_node;
        // increases the number of words
        word_counter++;
    }

    fclose(file);
    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    // return the total amount of words
    return word_counter;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    // count number of freed words
    unsigned int freed_words = 0;

    // iterate over all buckets
    for (int i = 0; i < BUCKETS; i++)
    {
        // if bucket is not null
        if (table[i] != NULL)
        {
            // get a cursor
            node* cursor = table[i];

            // free every node inside the bucket
            while (cursor != NULL)
            {
                node* tmp = cursor;
                cursor = cursor->next;
                free(tmp);
                freed_words++;
            }
        }
    }

    // compare freed words with total amount of words in the dictionary
    if (freed_words != word_counter)
        return false;

    // then return true if amount of words and freed words match
    return true;
}
