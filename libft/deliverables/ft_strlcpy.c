/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoseyusprogrammer <yoseyusprogrammer@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 16:43:45 by yoseyusprog       #+#    #+#             */
/*   Updated: 2026/05/04 17:06:27 by yoseyusprog      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	char	*source;
	size_t	i;
	size_t	srclen;

	source = (char *)src;
	srclen = ft_strlen(src);
	i = 0;
	while (i < size - 1 && source[i])
	{
		dst[i] = source[i];
		i++;
	}
	dst[i] = '\0';
	return (srclen);
}
