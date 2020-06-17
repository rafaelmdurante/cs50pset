#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 3

// Candidates have name and vote count
typedef struct
{
    string name;
    int votes;
}
candidate;

// Array of candidates
candidate candidates[MAX];

// Number of candidates
int candidate_count;

// Function prototypes
bool vote(string name);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    int voter_count = get_int("Number of voters: ");

    // Loop over all voters
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");

        // Check for invalid vote
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }

    // Display winner of election
    print_winner();
}

// Update vote totals given a new vote
bool vote(string name)
{
    // Iterate over candidates list
    for (int i = 0; i < MAX; i++)
    {
        // Compares the name and the name of the candidate of the array
        if (strcmp(name, candidates[i].name) == 0)
        {
            // Add a vote if the name is the same
            candidates[i].votes++;
            // Then return true
            return true;
        }
    }
    // Otherwise, return false
    return false;
}

// Print the winner (or winners) of the election
void print_winner(void)
{
    // Keep track of the highest votes value
    int most_votes = 0;

    // Iterate over the candidates votes
    for (int i = 0; i < MAX; i++)
        // Update the most_votes number with the highest
        if (candidates[i].votes > most_votes)
            most_votes = candidates[i].votes;

    // Since there might be a draw, iterate again
    for (int i = 0; i < MAX; i++)
        // And print all candidates with the highest votes
        if (candidates[i].votes == most_votes)
            printf("%s\n", candidates[i].name);
}
