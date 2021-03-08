//
//  mario.c
//  week_1_problemset
//
//  Created by Anmol Sandhu on 2021-02-12.
//
#include <stdio.h>

// user input variable for the height
int height = 0;

//print func prototype
void print(int n);
int checkinput(void);

int main(void)
{
    print(checkinput()); // calling print function that display the pattern

    return 0;
}

int checkinput(void)
{
    int flag = 0;

    while(flag == 0)
    {
        int status, input;
        char temp;
        printf("Height: ");
        status = scanf("%d", &input); // return 1 when scanf is succesful
        scanf("%c", &temp); //input '\n' at end of line(prevent from infinite loop)

        if (status != 1 || temp != '\n')   //status not 1 and dummy value in temp
        {

        }
        else if(input > 0 && input < 9){
            flag = 1;   //probably not required
            return input;   //after validation return input to print() function for pattern print
        }
    }
    return -99;
}

// printing the pyramid pattern param1: user height input
void print(int n)
{
//    if(n == -99)
//    {
//        exit the program
//    }
    int i, j;

    for(i=1; i<=n ; i++)
    {
        printf("%*s",n-i,"");   //for right alignment by n-i spaces.
        for( j=0 ; j<i ; j++) // printing left side pattern
        {
            printf("%s","#");
        }
        printf("  "); // space in the middle
        for( j=0 ; j<i ; j++) //printing right side pattern
        {
            printf("%s","#");
        }
        printf("\n");   // next row
    }
}
