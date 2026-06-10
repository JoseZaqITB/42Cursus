/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzaquina <jzaquina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 16:48:48 by jzaquina          #+#    #+#             */
/*   Updated: 2026/06/10 20:04:38 by jzaquina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

void	addstr(char	*ptr, char *str, int start)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ptr[start + i] = str[i];
		i++;
	}
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str1;
	char	*str2;
	char	*ptr;
	size_t	len1;
	size_t	len2;

	str1 = (char *)s1;
	str2 = (char *)s2;
	len1 = ft_strlen(str1);
	len2 = ft_strlen(str2);
	ptr = (char *)malloc((len1 + len2 + 1) * sizeof(char));
	if (!s1 || !s2 || !ptr)
		return (0);
	addstr(ptr, str1, 0);
	addstr(ptr, str2, len1);
	ptr[len1 + len2] = '\0';
	return (ptr);
}


int	ft_strchrn(const char *s, int c)
{
	unsigned char	chr;
	char			*str;
	int	i;

	str = (char *)s;
	chr = (unsigned char)c;
	while (1)
	{
		if (*str == chr)
			return (i);
		if (!*str)
			return (0);
		str++;
		i++;
	}
	return (0);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	actualsize;

	if (!s)
		return (0);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	actualsize = ft_strlen(s + start);
	if (len > actualsize)
		len = actualsize;
	ptr = (char *)ft_calloc(len + 1, sizeof(char));
	if (!ptr)
		return (0);
	ft_strlcpy(ptr, s + start, len + 1);
	return (ptr);
}
