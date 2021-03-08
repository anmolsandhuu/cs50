#include<stdio.h>
#include<cs50.h>
#include<string.h>
#include <stdlib.h>
#include<ctype.h>

void caesar(int i, string s);
int charToInt(char c);

int main(int argc, string argv[])
{
    if(argc == 2)
    {
        printf("argv[1] is %s\n", argv[1]);
        caesar(strlen(argv[1]), argv[1]);
    }
    else
    {
        printf("Usage: ./caesar key\n");
    }


    return 0;
}

void caesar(int len, string char_key)
{
    char set[26] = "abcdefghijklmnopqrstuvwxyz";
    int key[len], int_key = 0;
    for(int i=0; i<len; i++)
    {
        if(!isdigit(char_key[i]))
        {
            exit(9);
        }
        else
        {
             key[i] = charToInt(char_key[i]);
        }
    }

    for(int j=0; j<len; j++){
        int_key = int_key * 10;
        int_key = int_key + key[j];
    }
    string plain = get_string("plaintext: ");
    printf("-%s-", plain);
    int dumb = strlen(plain);
    char cipher[dumb];

    for(int k=0; k<dumb; k++)
    {
        for(int l=0; l<26; l++)
        {
            if(plain[k] == set[l])
            {
                int temp = ((l + int_key) % 26);
                //printf(":%i:", temp);
                cipher[k] = set[temp];
                //printf("%c", cipher[k]);
            }

        }
    }
    printf("ciphertext: ");
    for(int x=0; x<dumb; x++){
        printf("%c", cipher[x]);
    }
}

int charToInt(char c)
{
    return c - '0';
}