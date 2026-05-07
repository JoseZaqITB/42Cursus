/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoseyusprogrammer <yoseyusprogrammer@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 12:45:51 by yoseyusprog       #+#    #+#             */
/*   Updated: 2026/05/07 09:05:48 by yoseyusprog      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;
	unsigned char	chr;

	i = 0;
	chr = (unsigned char)c;
	str = (unsigned char *)s;
	while (i < n)
	{
		if (str[i] == chr)
			return (str + i);
		i++;
	}
	return (0);
}
