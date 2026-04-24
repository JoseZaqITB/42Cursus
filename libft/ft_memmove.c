/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoseyusprogrammer <yoseyusprogrammer@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 14:33:38 by yoseyusprog       #+#    #+#             */
/*   Updated: 2026/04/24 15:10:50 by yoseyusprog      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*s;
	char	*d;

	s = (char *)src;
	d = (char *)dest;
	if (d < s)
		ft_memcpy(dest, src, n);
	else
	{
		while (n--)
		{
			d[n] = s[n];
		}
	}
	return (dest);
}
