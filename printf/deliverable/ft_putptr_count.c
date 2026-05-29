/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr_count.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzaquina <jzaquina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 12:45:25 by jzaquina          #+#    #+#             */
/*   Updated: 2026/05/29 13:29:41 by jzaquina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr_count(unsigned long n, int count)
{
	int	cnt;

	cnt = 0;
	if (n >= 16)
	{
		cnt = ft_putptr_count(n / 16, ++count);
		ft_putchar_fd("0123456789abcdef"[n % 16], 1);
	}
	else
	{
		cnt += ft_putstr_count("0x");
		ft_putchar_fd("0123465789abcdef"[n], 1);
		cnt += ++count;
	}
	return (cnt);
}
