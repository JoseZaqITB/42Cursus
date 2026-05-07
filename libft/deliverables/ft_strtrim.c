/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoseyusprogrammer <yoseyusprogrammer@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 15:20:22 by yoseyusprog       #+#    #+#             */
/*   Updated: 2026/05/07 11:10:00 by yoseyusprog      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	cispart(char c, char *subelems)
{
	int	j;

	j = 0;
	while (subelems[j])
	{
		if (c == subelems[j])
			break ;
		else if (!subelems[j + 1])
			return (0);
		j++;
	}
	return (1);
}

int	strnelem(int *nelem, char c, char *subelems)
{
	int	j;

	j = 0;
	while (subelems[j])
	{
		if (c == subelems[j])
			(*nelem)++;
		else if (!subelems[j + 1])
			return (-1);
		j++;
	}
	return (0);
}

int	nsubelems(char *s1, char *subelems)
{
	int	i;
	int	nelem;

	i = 0;
	nelem = 0;
	while (s1[i])
	{
		if (strnelem(&nelem, s1[i], subelems) == -1)
			break ;
		i++;
	}
	i = ft_strlen(s1);
	while (--i)
		if (strnelem(&nelem, s1[i], subelems) == -1)
			break ;
	return (nelem);
}

void	deleteelems(char *newstr, char *src, char *subelems)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	j = ft_strlen(src);
	while (src[i])
	{
		if (!cispart(src[i], subelems))
			break ;
		i++;
	}
	while (j--)
	{
		if (!cispart(src[j], subelems))
			break ;
	}
	while (i <= j)
	{
		*newstr = src[i];
		newstr++;
		i++;
	}
	*newstr = '\0';
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str1;
	char	*str2;
	char	*ptr;
	int		nelem;

	str1 = (char *)s1;
	str2 = (char *)set;
	nelem = ft_strlen(str1) - nsubelems(str1, str2) + 1;
	ptr = ft_calloc(nelem, sizeof(char));
	deleteelems(ptr, str1, str2);
	return (ptr);
}
