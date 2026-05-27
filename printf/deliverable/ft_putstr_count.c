/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_count.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzaquina <jzaquina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 16:35:10 by jzaquina          #+#    #+#             */
/*   Updated: 2026/05/22 16:40:07 by jzaquina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_putstr_count(char *s)
{
	int	count;

	count = 0;
	while (*s)
	{
		ft_putchar_fd(*s++, 1);
		count++;
	}
	return (count);
}
