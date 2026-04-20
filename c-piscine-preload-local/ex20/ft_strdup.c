/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzaquina <jzaquina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 14:39:44 by yoseyusprog       #+#    #+#             */
/*   Updated: 2026/04/20 16:34:29 by jzaquina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

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
		return (NULL);
	while (src[i])
	{
		dpsrc[i] = src[i];
		i++;
	}
	dpsrc[i] = '\0';
	return (dpsrc);
}

/*
#include <stdio.h>

int	main(void)
{
	char	*src = "perro con sarna y soda";
	char	*dpsrc = ft_strdup(src);

	printf("%s | %s\n", src, dpsrc);

	free(dpsrc);
	dpsrc = NULL;
	return (0);
}
*
