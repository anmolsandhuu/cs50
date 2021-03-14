#include <cs50.h>
#include <stdio.h>

int collatz(int n);

int main()
{
    int n = get_int("Enter the number n: ");
    collatz(n);
    return 0;
}

int collatz(int n)
{
    printf("%i ", n);
    if(n ==1)
    {
        return 1;
    }
    else if((n % 2) == 0)
    {
        return collatz(n/2);
    }
    else
    {
        return collatz( (3 * n) + 1);
    }
}