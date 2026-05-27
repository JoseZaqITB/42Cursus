/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_count.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzaquina <jzaquina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 16:20:31 by jzaquina          #+#    #+#             */
/*   Updated: 2026/05/27 16:16:15 by jzaquina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_putnbr_count(int n)
{
	char	*ns;
	int		len;

	ns = ft_itoa(n);
	len = ft_putstr_count(ns);
	return (len);
}
