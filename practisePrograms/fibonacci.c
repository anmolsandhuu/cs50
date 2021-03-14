#include <cs50.h>
#include <stdio.h>

int fibonacci(int n);

int main()
{
    int n = get_int("Enter the number n: "), c =0;

    for(int i=1; i <= n; i++)
    {
        printf("%d\n", fibonacci(c));
        c++;
    }
    return 0;
}

int fibonacci(int n)
{
    if(n == 0)
    {
        return 0;
    }
    else if(n == 1)
    {
        return 1;
    }
    else
    {
        return (fibonacci(n-1) + fibonacci(n-2));
    }
}