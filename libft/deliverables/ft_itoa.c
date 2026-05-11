/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzaquina <jzaquina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 16:41:14 by jzaquina          #+#    #+#             */
/*   Updated: 2026/05/11 16:41:15 by jzaquina         ###   ########.fr       */
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
	int		currn;

	len = lenint(n);
	nstr = ft_calloc(len + 1, sizeof(char));
	if (!nstr)
		return (0);
	nstr[len] = '\0';
	if (n == 0)
		nstr[0] = '0';
	if (n < 0)
	{
		nstr[0] = '-';
	}
	while (n != 0)
	{
		currn = n % 10;
		if (currn < 0)
			currn *= -1;
		nstr[--len] = currn + '0';
		n /= 10;
	}
	return (nstr);
}
