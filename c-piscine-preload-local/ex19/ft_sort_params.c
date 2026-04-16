/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzaquina <jzaquina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 15:32:23 by jzaquina          #+#    #+#             */
/*   Updated: 2026/04/16 17:24:43 by jzaquina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_putchar(char c);

void	ft_print_string(char *str)
{
	while (*str)
	{
		ft_putchar(*str);
		str++;
	}
}

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 == *s2 && (*s1 || *s2))
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

void	bubble_sort(int argc, char *argv[])
{
	char	*temp;
	int		i;
	int		sorted;

	i = 1;
	sorted = 0;
	temp = argv[1];
	while (i < argc - 1)
	{
		if (ft_strcmp(argv[i], argv[i + 1]) > 0)
		{
			temp = argv[i];
			argv[i] = argv[i + 1];
			argv[i + 1] = temp;
			bubble_sort(argc, argv);
		}
		if (sorted != 0)
			bubble_sort(argc, argv);
		i++;
	}
}


int	main(int argc, char *argv[])
{
	int	i;

	i = 1;
	bubble_sort(argc, argv);
	while (i < argc)
	{
		ft_print_string(argv[i]);
		ft_putchar('\n');
		i++;
	}
	return (0);
}
