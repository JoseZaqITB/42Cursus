/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzaquina <jzaquina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 16:48:48 by jzaquina          #+#    #+#             */
/*   Updated: 2026/06/08 12:14:57 by jzaquina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	fn_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

int	get_linebreak(char *buffer, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (buffer[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*append_str(char *str1, char str2[])
{
	int		str1_len;
	int		str2_len;
	char	*res;

	str1_len = fn_strlen(str1);
	str2_len = fn_strlen(str2);
	res = malloc((str1_len * str2_len + 1) * sizeof(char));
	while (*str1)
	{
		*res++ = *str1++;
	}
	while (*str2)
	{
		*res++ = *str2++;
	}
	*res = '\0';
	return (res);
}

