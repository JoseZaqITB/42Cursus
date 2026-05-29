/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrhex_count.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzaquina <jzaquina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 19:19:34 by jzaquina          #+#    #+#             */
/*   Updated: 2026/05/29 13:53:57 by jzaquina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbrhex_count(unsigned int n, int count, int lower)
{
	int	cnt;

	cnt = 0;
	if (n >= 16)
	{
		cnt = ft_putnbrhex_count(n / 16, ++count, lower);
		if (lower)
			ft_putchar_fd("0123456789abcdef"[n % 16], 1);
		else
			ft_putchar_fd("0123456789ABCDEF"[n % 16], 1);
	}
	else
	{
		if (lower)
			ft_putchar_fd("0123456789abcdef"[n], 1);
		else
			ft_putchar_fd("0123456789ABCDEF"[n], 1);
		cnt = ++count;
	}
	return (cnt);
}
