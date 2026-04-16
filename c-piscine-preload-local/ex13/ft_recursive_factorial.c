/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzaquina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 13:35:38 by jzaquina          #+#    #+#             */
/*   Updated: 2026/04/16 13:36:15 by jzaquina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_factorial(int nb)
{
	int	fact;

	if (nb <= 0)
		return (0);
	if (nb == 1)
		return (nb);
	fact = nb * ft_recursive_factorial(nb - 1);
	return (fact);
}
/*
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
*/
