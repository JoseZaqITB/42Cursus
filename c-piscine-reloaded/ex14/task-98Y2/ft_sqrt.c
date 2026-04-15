int ft_sqrt(int nb)
{
    int i;

    i = 0;
    while(i * i <= nb)
    {
        if(i * i  == nb)
            return (i);
        i++;
    }
    return (0);
}
/*
#include <stdio.h>

int main(void)
{
    int i = 10;
    while(i >= -2)
    {
        printf("%d\n",ft_sqrt(i));
        i--;
    }

    return (0);
}
*/