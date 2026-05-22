/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzaquina <jzaquina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 16:42:37 by jzaquina          #+#    #+#             */
/*   Updated: 2026/05/11 16:42:38 by jzaquina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*s;
	char	*d;

	if (!dest && !src)
		return (0);
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
