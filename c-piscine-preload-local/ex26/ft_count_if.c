/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzaquina <jzaquina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 19:00:54 by jzaquina          #+#    #+#             */
/*   Updated: 2026/04/23 11:19:24 by jzaquina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_count_if(char **tab, int (*f)(char*))
{
	int	total;
	int	i;

	total = 0;
	i = 0;
	while (tab[i])
	{
		if ((*f)(tab[i]) == 1)
			total++;
		i++;
	}
	return (total);
}

/*
#include <stdio.h>

int	ft_one(char *str)
{
	printf("%c", *str);
	if (*str != 'a')
		return (1);
	return (0);
}


int	main()
{
	char *tabArray[] = {"Gato", "aerro", "Oso", 0};
	char **tab = tabArray;
	int total = ft_count_if(tab, &ft_one);
	printf("%d", total);

}
*/
