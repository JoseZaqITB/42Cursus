int ft_recursive_factorial(int nb)
{
    int fact;

    if(nb <= 0)
        return (0);
    if(nb == 1)
        return (nb);
    fact = nb * ft_recursive_factorial(nb - 1);
    return (fact);
}

#include <stdio.h>

int main(void)
{
    int i = 10;
    while(i >= -2)
    {
        printf("%d\n",ft_recursive_factorial(i));
        i--;
    }

    return (0);
}