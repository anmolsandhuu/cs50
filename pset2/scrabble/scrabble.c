#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // Print the winner
    if(score1 == score2){
        printf("Tie!");
    }
    else if(score1 > score2)
    {
        printf("Player 1 wins!");
    }
    else
    {
        printf("Player 2 wins!");
    }
}


int compute_score(string word)
{
    int len = strlen(word), total = 0;  //len is lenght of input; initialize total =0
    string character = "abcdefghijklmnopqrstuvwxyz";

    for(int i=0; i<len; i++)    //for every char in user input
    {
        for(int j=0; j<26; j++) //loop each char from user input 26 times to get the index
        {
            if(isalpha(word[i]))
            {
                if(tolower(word[i]) == character[j])
                {
                    total = total + POINTS[j];
                }
            }
        }
    }
    return total;   //return int total
}