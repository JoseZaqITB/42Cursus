/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoseyusprogrammer <yoseyusprogrammer@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 09:15:52 by yoseyusprog       #+#    #+#             */
/*   Updated: 2026/05/07 17:31:30 by yoseyusprog      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	checksubstr(char *big, char *little, int index, size_t len)
{
	size_t	j;

	j = 1;
	while (big[index + j] == little[j] && big[index + j] && index + j < len)
		j++;
	if (!little[j])
		return (1);
	return (0);
}

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	char	*s1;
	char	*s2;
	size_t	i;

	s1 = (char *)big;
	s2 = (char *)little;
	i = 0;
	if (!s2[0])
		return (s1);
	while (big[i] && i < len)
	{
		if (s1[i] == s2[0] && checksubstr(s1, s2, i, len))
		{
			s1 += i;
			return (s1);
		}
		i++;
	}
	return (0);
}
