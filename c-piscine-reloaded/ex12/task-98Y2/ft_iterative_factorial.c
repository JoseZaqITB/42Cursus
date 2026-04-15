int ft_iterative_factorial(int nb)
{
    int     i;
    int     fact;

    i = nb;
    fact = 1;
    while(i > 1)
    {
        fact *= i;
        i--;
    }
    return (fact);
}
/*
#include <stdio.h>

int main(void)
{
    int i = 10;
    while(i >= -2)
    {
        printf("%d\n",ft_iterative_factorial(i));
        i--;
    }

    return (0);
}
*/