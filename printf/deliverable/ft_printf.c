/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzaquina <jzaquina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 17:58:29 by jzaquina          #+#    #+#             */
/*   Updated: 2026/06/09 10:39:45 by jzaquina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static int	printvar(char type, va_list vargs)
{
	int	c;

	c = 1;
	if (type == 'c')
		ft_putchar_fd((char)va_arg(vargs, int), 1);
	else if (type == 's')
		c = ft_putstr_count(va_arg(vargs, char *));
	else if (type == 'p')
		c = ft_putptr_count(va_arg(vargs, unsigned long));
	else if (type == 'd' || type == 'i')
		c = ft_putnbr_count(va_arg(vargs, int));
	else if (type == 'u')
		c = ft_putunbr_count(va_arg(vargs, unsigned int), 0);
	else if (type == 'x')
		c = ft_putnbrhex_count(va_arg(vargs, unsigned int), 0, 1);
	else if (type == 'X')
		c = ft_putnbrhex_count(va_arg(vargs, unsigned int), 0, 0);
	else if (type == '%')
		ft_putchar_fd('%', 1);
	return (c);
}

int	ft_printf(char const *str, ...)
{
	int		n;
	va_list	vargs;

	n = 0;
	va_start(vargs, str);
	while (*str)
	{
		if (*str == '%')
		{
			if (*(str + 1) == '\0')
				return (-1);
			n += printvar(*(++str), vargs);
		}
		else
		{
			ft_putchar_fd(*str, 1);
			n++;
		}
		str++;
	}
	va_end(vargs);
	return (n);
}
