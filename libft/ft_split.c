/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoseyusprogrammer <yoseyusprogrammer@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 17:32:54 by yoseyusprog       #+#    #+#             */
/*   Updated: 2026/04/28 11:55:08 by yoseyusprog      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	getnextword(char *str, int start, char c)
{
	int	i;

	i = 0;
	while (1)
	{
		if (!str[start + i])
			return (-1);
		if (str[start + i] == c)
			break ;
		i++;
	}
	while (str[start + i] == c && str[start + i] == str[start + i + 1])
	{
		i++;
	}
	return (start + i + 1);
}

static int	getelembydel(char *str, char del)
{
	int	nelem;
	int	i;

	nelem = -1;
	i = 0;
	while (str[i])
	{
		nelem++;
		i = getnextword(str, i, del);
		if (i == -1)
			break ;
	}

	return (nelem);
}

static void	free_all(char **list)
{
	int	i;

	i = -1;
	while (list[++i])
		free(list[i]);
	free(list);
	list = 0;
}

static void	completelist(char **list, int len, char *str, char del)
{
	int	i;
	int	subi;
	int	nstrelem;

	i = 0;
	nstrelem = 0;
	subi = 0;
	while (i < len)
	{
		subi = getnextword(str, subi, del);
		while (str[subi + nstrelem] != del)
			nstrelem++;
		list[i] = ft_substr(str, subi, nstrelem);
		if (!list[i])
		{
			free_all(list);
			return ;
		}
		nstrelem = 0;
		i++;
	}
}

char	**ft_split(char const *s, char c)
{
	char	*str;
	int		nelem;
	char	**list;

	str = (char *)s;
	nelem = getelembydel(str, c);
	list = ft_calloc(nelem + 1, sizeof(char *));
	if (!list)
		return (0);
	list[nelem] = 0;
	completelist(list, nelem, str, c);
	return (list);
}
