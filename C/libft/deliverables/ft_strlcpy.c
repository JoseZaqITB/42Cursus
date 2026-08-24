/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzaquina <jzaquina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 16:43:38 by jzaquina          #+#    #+#             */
/*   Updated: 2026/05/11 16:43:39 by jzaquina         ###   ########.fr       */
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
	if (size == 0)
		return (srclen);
	while (i < (size - 1) && source[i])
	{
		dst[i] = source[i];
		i++;
	}
	dst[i] = '\0';
	return (srclen);
}
