/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzaquina <jzaquina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 13:34:40 by jzaquina          #+#    #+#             */
/*   Updated: 2026/04/16 15:27:54 by jzaquina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	fact;

	if (nb < 0 || nb > 13)
		return (0);
	fact = 1;
	while (nb > 1)
	{
		fact *= nb;
		nb--;
	}
	return (fact);
}
/*
#include <stdio.h>

int main(void)
{
    int i = 14;
	while(i >= -2)
	{
        printf("%d\n",ft_iterative_factorial(i));
        i--;
    }

    return (0);
}
*/
