/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoseyusprogrammer <yoseyusprogrammer@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 11:03:47 by yoseyusprog       #+#    #+#             */
/*   Updated: 2026/04/28 11:55:37 by yoseyusprog      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	lenint(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int		len;
	char	*nstr;

	len = lenint(n);
	nstr = ft_calloc(len + 1, sizeof(char));
	nstr[len] = '\0';
	if (!nstr)
		return (0);
	if (n < 0)
	{
		nstr[0] = '-';
		n *= -1;
	}
	while (n != 0)
	{
		nstr[--len] = n % 10 + '0';
		n /= 10;
	}
	return (nstr);
}
