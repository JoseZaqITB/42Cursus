/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_foreach.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzaquina <jzaquina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 18:19:36 by jzaquina          #+#    #+#             */
/*   Updated: 2026/04/20 18:59:50 by jzaquina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_foreach(int *tab, int length, void (*f)(int))
{
	int	i;

	i = 0;
	while (i < length)
	{
		(*f)(tab[i]);
		i++;
	}
}

/*
#include <stdio.h>
void	print_int(int n)
{
	printf("|%d|", n);
}

int	main(void)
{
	int n[] = {1,2,3,4,5,6,67,7,8,8};
	int	*tab = n;
	ft_foreach(tab, 10, &print_int);
	return (0);
}
*/
