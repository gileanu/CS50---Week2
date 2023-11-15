#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

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

    if (score1 > score2) // for Player1 Wins
    {
        printf("Player 1 wins!\n");
    }
    else if (score1 < score2) // for Player2 Wins
    {
        printf("Player 2 wins!\n");
    }
    else // catchall Tie
    {
        printf("Tie!\n");
    }
}

int compute_score(string word)
{
    // initialize a int score to keep track of the value of each letter
    int score = 0;
    for (int i = 0; i < strlen(word); i++)
    {
        if (isupper(word[i])) // check if its uppercase letter
        {
            score += POINTS[word[i] - 65]; // asign score value from POINTS[] array
        }
        else if (islower(word[i])) // check if its lowercase letter
        {
            score += POINTS[word[i] - 97]; // asign score value from same POINTS[] array
        }
    }
    // from string word to int number
    return score;
}