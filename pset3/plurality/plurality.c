#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

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
            i--;
        }
    }

    // Display winner of election
    print_winner();
}

// Update vote totals given a new vote
bool vote(string name)
{
    // adding +1 on vote of every candidate voted for
    for(int i=0; i<candidate_count; i++)
    {
        if(strcmp(name, candidates[i].name) == 0){
            candidates[i].votes = candidates[i].votes + 1;

            return true;
        }
    }
    return false;
}

// Print the winner (or winners) of the election
void print_winner(void)
{

    candidate temp; //temp variable of candidate type

    //selcetion sort on votes
    //after this sort the candidate will be in ascending order with respect to their votes
    for(int i=0; i<candidate_count; i++)
    {
        for(int j=i+1; j < candidate_count; j++)
        {
            if(candidates[i].votes > candidates[j].votes)
            {
                temp = candidates[i];

                candidates[i] = candidates[j];

                candidates[j] = temp;
            }
        }
    }

    int winningVote = candidates[candidate_count-1].votes;

    //loop through all candidate and print their name is their vote is equal to winning vote
    for(int i=candidate_count-1; i>=0; i--)
    {
        if(winningVote == candidates[i].votes)
        {
            printf("%s\n", candidates[i].name);
        }
    }

    return;
}

