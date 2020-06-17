// caesar cipher (https://cs50.harvard.edu/x/2020/psets/2/caesar/)
#include <stdio.h>
#include <ctype.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>

/*
 * METHOD DECLARATIONS
 */
bool validate_args(int argc, string key);
void print_cipher(string plaintext, string key);

/*
 * MAIN METHOD
 */
int main(int argc, string argv[])
{
    // validate arguments
    if (!validate_args(argc, argv[1]))
    {
        return 1;
    }
    string text = get_string("plaintext: ");
    print_cipher(text, argv[1]);
}

/*
 * METHOD DEFINITIONS
 */

// validate arguments passed by user through command-line
bool validate_args(int argc, string key)
{
    // must have only one command-line arg
    if (argc != 2)
    {
        // if there are more than one, print instructions
        printf("You must provide one key to shift your text.\n");
        return false;
    }
    // if argv is not a valid positive decimal digit
    for (int i = 0; i < strlen(key); i++)
    {
        if (!isdigit(key[i]))
        {
            printf("Usage: ./caesar key\n");
            return false;
        }
    }
    // if all validations pass return true
    return true;
}

// shift the plaintext based on the key provided by user via command-line
void print_cipher(string text, string key)
{
    printf("ciphertext: ");
    // convert string key into integer key
    int k = atoi(key);
    // iterate through text and shift it
    for (int i = 0; i < strlen(text); i++)
    {
        int initial = isupper(text[i]) ? 'A' : 'a';
        printf("%c", isalpha(text[i]) ? ((text[i] - initial) + k) % 26 + initial : text[i]);
    }
    // print end of line
    printf("\n");
}