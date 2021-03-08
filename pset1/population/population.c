#include <stdio.h>
#include <cs50.h>

int calculate_population(void);     //prototype of function where calculations takes place

int main(void)
{
    int year = calculate_population();
    printf("Years: %d\n", year);
    return 0;
}

int calculate_population(void)
{
    int initial = 0, final = 0, years = 0;

    do  // getting inital size and repeating until it passes required parameters i.e its greater than or equal to 9
    {
        printf("Start size: ");
        scanf("%d", &initial);
        printf("\n");
    }
    while(initial < 9);

    do  // getting final size and repeating until it passes required parameters i.e its greating than inital
    {
        printf("End size: ");
        scanf("%d", &final);
        printf("\n");
    }
    while (final < initial);


    do
    {

        int born, dead, oneyear;

        born = initial / 3;
        dead = initial / 4;

        oneyear = initial + (initial / 3) - (initial / 4);  // one year progress after n/3 born an n/4 dead from intial population

        if (initial == final)
        {
            return 0;
        }
        years++;

        initial = oneyear;


    }
    while(initial < final); 

    return years;
}