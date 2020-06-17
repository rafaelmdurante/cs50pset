// caesar cipher (https://cs50.harvard.edu/x/2020/psets/2/caesar/)
#include <stdio.h>
#include <ctype.h>
#include <cs50.h>
#include <string.h>

/*
 * METHOD DECLARATIONS
 */
bool validate_args(int argc, string key[]);
void print_cipher(string plaintext, string key);
int get_alphabet_index(char character);

/*
 * MAIN METHOD
 */
int main(int argc, string argv[])
{
    // validate arguments
    if (!validate_args(argc, argv))
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
bool validate_args(int argc, string argv[])
{
    // must have only one command-line arg
    if (argc != 2)
    {
        // only accepts print instructions
        printf("Usage: ./substitution KEY\n");
        return false;
    }

    string key = argv[1];
    int length = strlen(key);
    // check if key has 26 characters
    if (length != 26)
    {
        printf("Key must contain 26 characters.\n");
        return false;
    }
    // if argv is not a valid positive decimal digit
    for (int i = 0; i < length; i++)
    {
        // validate only alphabetic characters
        if (!isalpha(key[i]))
        {
            printf("Key must only contain alphabetic characters.\n");
            return false;
        }
        // validate only non repeated chars
        for (int j = i + 1; j < length; j++)
        {
            if (tolower(key[i]) == tolower(key[j]))
            {
                printf("Key must not contain repeated characters.\n");
                return false;
            }
        }
    }
    // if all validations pass return true
    return true;
}

// shift the plaintext based on the key provided by user via command-line
void print_cipher(string text, string key)
{
    int length = strlen(text);
    printf("ciphertext: ");
    // iterate through text and shift it
    for (int i = 0; i < length; i++)
    {
        char cipher = isalpha(text[i]) ? key[get_alphabet_index(text[i])] : text[i];
        printf("%c", islower(text[i]) ? tolower(cipher) : toupper(cipher));
    }
    // print end of line
    printf("\n");
}

// return the index of a letter in the alphabet
int get_alphabet_index(char character)
{
    string alphabet = "abcdefghijklmnopqrstuvwxyz";
    int length = strlen(alphabet);
    char lch = tolower(character);
    // iterate over the alphabet to get the index
    for (int i = 0; i < length; i++)
    {
        if (lch == alphabet[i])
        {
            return i;
        }
    }
    return -1;
}