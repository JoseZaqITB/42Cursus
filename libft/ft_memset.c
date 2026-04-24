/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoseyusprogrammer <yoseyusprogrammer@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 12:01:13 by yoseyusprog       #+#    #+#             */
/*   Updated: 2026/04/24 13:56:09 by yoseyusprog      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;
	char	*ps;

	i = 0;
	ps = (char *)s;
	while (i < n)
	{
		ps[i++] = c;
	}
	return (s);
}
