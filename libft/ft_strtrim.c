/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoseyusprogrammer <yoseyusprogrammer@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 15:20:22 by yoseyusprog       #+#    #+#             */
/*   Updated: 2026/04/27 16:39:20 by yoseyusprog      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	nsubelems(char *s1, char *subelems)
{
	int	i;
	int	j;
	int	nelem;


	i = 0;
	j = 0;
	nelem = 0;
	while (s1[i])
	{
		while (subelems[j])
		{
			if (s1[i] == subelems[j])
				nelem++;
			j++;
		}
		j = 0;
		i++;
	}
	return (nelem);
}

void	deleteelems(char *newstr, char *src, char *subelems)
{
	int	i;
	int	j;
	int	k;
	int	len;

	i = -1;
	j = -1;
	k = 0;
	len = ft_strlen(subelems);
	while (src[++i])
	{
		while (subelems[++j])
		{
			if (src[i] == subelems[j])
				break ;
		}
		if (j == len)
		{
			newstr[k] = src[i];
			k++;
		}
		j = -1;
	}
	newstr[++k] = '\0';
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
