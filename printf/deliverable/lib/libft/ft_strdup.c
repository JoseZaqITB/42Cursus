/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzaquina <jzaquina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 16:43:17 by jzaquina          #+#    #+#             */
/*   Updated: 2026/05/11 16:43:18 by jzaquina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *src)
{
	char	*dpsrc;
	int		length;
	int		i;

	length = sizeof(char);
	i = 0;
	while (src[i])
	{
		length += sizeof(char);
		i++;
	}
	i = 0;
	dpsrc = malloc(length);
	if (!dpsrc)
		return (0);
	while (src[i])
	{
		dpsrc[i] = src[i];
		i++;
	}
	dpsrc[i] = '\0';
	return (dpsrc);
}
