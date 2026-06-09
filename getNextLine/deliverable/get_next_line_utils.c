/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzaquina <jzaquina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 16:48:48 by jzaquina          #+#    #+#             */
/*   Updated: 2026/06/09 16:54:59 by jzaquina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

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

char	*ft_substr(char const *s, unsigned int start, int len)
{
	char	*ptr;
	int		actualsize;
	int		i;

	i = 0;
	if (!s)
		return (0);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	actualsize = ft_strlen(s + start);
	if (len > actualsize)
		len = actualsize;
	ptr = (char *)malloc((len + 1) * sizeof(char));
	if (!ptr)
		return (0);
	while (i < len && s[start + i])
	{
		ptr[i] = s[start + i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
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
	char	*baseres;

	str1_len = ft_strlen(str1);
	str2_len = ft_strlen(str2);
	res = malloc((str1_len + str2_len + 1) * sizeof(char));
	baseres = res;
	while (*str1)
	{
		*res++ = *str1++;
	}
	while (*str2)
	{
		*res++ = *str2++;
	}
	*res = '\0';
	return (baseres);
}
