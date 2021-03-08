#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



void substitution(int argc, string argv);

//get_string from CS50.h

int main(int argc, string argv[]){
    int count = 0;

    //checking if arg are 2
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;

    }
    else if(strlen(argv[1]) == 26)    //check is len of arg is 26
    {
        int lenn = strlen(argv[1]);

        for(int i=0; i < lenn; i++) //checking if any char is repeated in the key provided as a command line arg
        {
            for(int j = i+1; j < lenn; j++)
            {
                if(argv[1][i] == argv[1][j])
                {
                    count++;
                }
            }
        }

        if(count == 0)
        {
            substitution(strlen(argv[1]), argv[1]); //calling logic function
            return 0;
        }
        else
        {
            return 1;
        }
    }
    else
    {
        printf("Key must contain 26 characters. \n");
        return 1;
    }

}

void substitution(int len, string argv)
{

    char key[len];      //creating array of same length as input
    string character = "abcdefghijklmnopqrstuvwxyz";

    //converting from upper case to lower case
    for(int i=0; i < len; i++)
    {
        if(isalpha(argv[i]))
        {
            key[i] = tolower(argv[i]);
        }
        else
        {
            exit(1);    //exit if key contains anything else than a char
        }

    }

    //asking for user cipher
    string userinput = get_string("plaintext: ");
    int user_len = strlen(userinput);

    char cipher[user_len];

    for (int i=0; i < user_len; i++)    //for every char in user_input
    {
        for(int j=0; j < len; j++)      //for every key char
        {
            if(isalpha(userinput[i]))   //check if user input is char
            {
                if(islower(userinput[i]))   //check case of character
                {
                    if(userinput[i] == character[j])
                    {
                    cipher[i]=key[j];
                    }
                    }

                    else
                    {
                    if(userinput[i] == toupper(character[j]))   //in case user_input is Upper case
                    {
                    cipher[i]=toupper(key[j]);
                    }
                    }
            }
            else if(isspace(userinput[i]))  //is there is spac btw two char strings
            {
                cipher[i]=' ';
            }
            else
            {
                cipher[i]=userinput[i]; // if user_input conatain special character
            }
        }

    }

    printf("ciphertext: "); //printing cipher char
    for(int f = 0; f < user_len; f++)
    {
        printf("%c", cipher[f]);
    }
    printf("\n");

}

