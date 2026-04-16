/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_alphabet.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzaquina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 13:22:07 by jzaquina          #+#    #+#             */
/*   Updated: 2026/04/16 13:27:39 by jzaquina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "stdio.h"
void	ft_putchar(char c);
/*{
    printf("%c", c);
}
*/

void	ft_print_alphabet(void)
{
	int	i;

	i = 97;
	while (i <= 122)
	{
		ft_putchar(i);
		i++;
	}
}
/*
int main(void)
{
    ft_print_alphabet();
}
*/
