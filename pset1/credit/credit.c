//
//  main.c
//  week_1_problem
//  Created by Anmol Sandhu on 2021-02-12.
//
//  Luhn’s Algorithm
//
#include <stdio.h>
#include <math.h>

void validateCredit(long int input);
long int validateInput(void);
int count(long int input);

int main(void)
{
    validateCredit(validateInput());
    //validateInput();
    return 0;
}
long int validateInput(void)
{
    int status, flag = 1, counter = 0;
    long int input, temp;
    char dummy;

    while(flag) {
        printf("Number: ");
        status = scanf("%ld", &input);
        scanf("%c", &dummy);

        if (status != 1 || dummy != '\n')   //loop if input is a char
        {

        }
        else if(input > 0)  // check if input is not -ve or zero
        {
            counter = count(input);
            if (counter == 10)     // if number is less than 13 loop
            {
                printf("INVALID\n");
            }
            else
            {
                flag = 0;       // all check passed, break while loop and return the number
            }
        }
    }
    return input;
}

int count(long int input){
    long temp = input;
    int count = 0;
    while (temp != 0)   //check the length of input number
    {
        temp /= 10;
        count++;
    }
    return count;
}

void validateCredit(long int input)
{
    long int user_input = input;
    int long temp = 0;
    int long total = 0, othertotal = 0;
    int counter = count(input);

    for (int i = 0; i < counter; i++) {
        temp = input % 10;
        input /= 10;
        if(i % 2 != 0){

            if (count(temp *2) == 2){
                total = total + ((int)temp * 2) % 10 + ((int) temp *2 ) / 10;

            } else{

                total = total + (temp * 2);
            }
        } else {
            othertotal = othertotal + temp;


                }
            }


    long final = othertotal + total;

    if (final % 10 == 0 )
    {
        int first_num = (user_input / pow( 10, (count(user_input) - 1 )));
        int first_two_num = (user_input / pow( 10, (count(user_input) - 2 )));

        if(first_num == 4 &&  count(user_input) > 12 && count(user_input) < 17)
        {
            printf("VISA\n");
        } else if ((first_two_num == 34 || first_two_num == 37) && (count(user_input) == 15))
        {
            printf("AMEX\n");
        } else if ((first_two_num > 50 && first_two_num < 56) && (count(user_input) == 16))
        {
            printf("MASTERCARD\n");
        } else{
            printf("INVALID\n");
        }

    }

}