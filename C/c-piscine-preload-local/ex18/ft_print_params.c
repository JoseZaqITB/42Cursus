/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzaquina <jzaquina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 14:24:53 by jzaquina          #+#    #+#             */
/*   Updated: 2026/04/16 17:19:44 by jzaquina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
void	ft_putchar(char c);

void	ft_print_string(char *str)
{
	while (*str)
	{
		ft_putchar(*str);
		str++;
	}
}

int	main(int argc, char *argv[])
{
	int	i;

	i = 1;
	while (i < argc)
	{
		ft_print_string(argv[i]);
		ft_putchar('\n');
		i++;
	}
}
