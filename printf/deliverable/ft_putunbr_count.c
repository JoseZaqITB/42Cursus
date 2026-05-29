/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr_count.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzaquina <jzaquina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 17:23:53 by jzaquina          #+#    #+#             */
/*   Updated: 2026/05/29 13:29:41 by jzaquina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunbr_count(unsigned int n, int count)
{
	int	cnt;

	cnt = 0;
	if (n >= 10)
	{
		cnt = ft_putunbr_count(n / 10, ++count);
		ft_putchar_fd(((n % 10) + '0'), 1);
	}
	else
	{
		ft_putchar_fd((n + '0'), 1);
		cnt = ++count;
	}
	return (cnt);
}
