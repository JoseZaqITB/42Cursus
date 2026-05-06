/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzaquina <jzaquina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 13:45:58 by jzaquina          #+#    #+#             */
/*   Updated: 2026/04/30 14:25:06 by jzaquina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t siz)
{
	char	*source;
	size_t	i;
	size_t	dest_size;
	size_t	src_size;

	source = (char *)src;
	i = 0;
	src_size = ft_strlen(source);
	dest_size = ft_strlen(dst);
	while (dst[i])
	{
		if (!(i < siz - 1))
			break ;
		i++;
	}
	while (source && i < siz - 1)
	{
		dst[i] = *source;
		source++;
		i++;
	}
	dst[++i] = '\0';
	if (siz < dest_size)
		return (src_size + siz);
	return (src_size + dest_size);
}
