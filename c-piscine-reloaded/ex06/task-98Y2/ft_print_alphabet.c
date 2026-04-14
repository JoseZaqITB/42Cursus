//#include "stdio.h"
void    ft_putchar(char c);
/*{
    printf("%c", c);
}
*/
void    ft_print_alphabet(void)
{
    int i;

    i = 97;
    while(i <= 122)
    {
        ft_putchar(i);
        i++;
    }
}

int main(void)
{
    ft_print_alphabet();
}