# Speller

The task is to check if a word is spelled correctly or not 
as quickly as possible.

## Project Structure

FILE          | DEFINITION
---------     | --------
speller.c     | the code that will do the spell checking based on `dictionary.h`
dictionary.h  | the declarations of the methods
dictionary.c  | where the actual methods are (work here)
Makefile      | compiler instructions
dictionaries/ | folder with the list of words
texts/        | sample files
keys/         | the solutions, list of words that are mispelled

## Dictionary.c

Functions to implement:

### load()

Load all the words of a dictionary into a data structure like a hash table.

```c
bool load(const char *dictionary)
{
  // TODO
}
```

It should store the dictionary inside of a *Hash Table*.

Every node has a value, a pointer to the next node.

```c
char word[LENGTH + 1]
struct node *next
```

Definition of node is in `dictionary.c`.

Allocating memory to a node:

```c
node *n = malloc(sizeof(node));
strcpy(n->word, "Hello");
n->next = NULL;
```

#### Open the Dictionary

- Open dictionary file
  - Use `fopen`
  - Remember to check if return value is `NULL`
- Read strings from file one at a time
  - `fscanf(file, "%s", word)`
  - `fscanf` will return `EOF` once it reaches end of file
- Create a new node for each word
  - Use `malloc`
  - Remember to check if return value is `NULL`
  - Copy word into node using `strcpy`
- Hash word to obtain a hash value
  - Takes a string and returns an index
- Insert node into hash table at that location
  - Recall that hash table is an array of linked lists
  - Be sure to set pointers in the correct order!

### hash()

Takes a word as input and outputs a number corresponding to which "bucket"
to store the word in.

```c
unsigned int hash(const char *word)
{
  // TODO
}
```

- Input: word, with alphabetical characters and (possibly) apostrophes
- Output: numerical index between `0` and `N - 1`, inclusive
- It should be *deterministic*

Larger `N` means more buckets.
If your function ends up with a value greater than `N`, you can take the value
`% N` to get a value in the appropriate range.

### size()

How many words in the dictionary.

Keep track of the words as you load them so it is easier to get the amount
of words.

### check()

Is this word in the dictionary or not.

```c
bool check(const char *word)
{
  // hash word to obtain a hash value
  // access linked list at the index in the hash table
  // traverse linked list, looking for the word by using a cursor
}
```

- Return `true` if the word is in the dictionary, `false` otherwise
- Case insensitive

Make use of `strcasecmp()` declared in `strings.h`. 

To traverse a linked list:

- Start with cursor set to first item in linked list
- Keep moving cursor until you get to `NULL`, checking each node for the word.

### unload()

Free up all memory of the data structure.

```c
bool unload(void)
{
  // TODO
}
```

Go through the hash table and free all nodes from the linked lists.

A `cursor` moves from a node to another and a `tmp` can free the node before
where cursor is.

-------

> Harvard's CS50
