/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoseyusprogrammer <yoseyusprogrammer@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 12:22:14 by yoseyusprog       #+#    #+#             */
/*   Updated: 2026/04/27 09:10:08 by yoseyusprog      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	char	*str1;
	char	*str2;

	str1 = (char *)s1;
	str2 = (char *)s2;
	i = 0;
	while (str1[i] == str2[i] && i < n - 1)
	{
		if (!str1[i])
			return (str1[i] - str2[i]);
		i++;
	}
	if (n == 0)
		return (0);
	return (str1[i] - str2[i]);
}
