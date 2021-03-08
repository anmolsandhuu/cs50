#include <stdio.h>
#include <cs50.h>

int main(void)
{
    string name = get_string("What is your name?\n");   //getting user input
    printf("hello, %s\n", name);                        //printing user name as a custom string
    
    return 0;
}