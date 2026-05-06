/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoseyusprogrammer <yoseyusprogrammer@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 11:28:07 by yoseyusprog       #+#    #+#             */
/*   Updated: 2026/04/27 11:49:11 by yoseyusprog      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	char	*ptr;
	size_t	i;

	str = (char *)s;
	i = 0;
	ptr = malloc(len * sizeof(char) + sizeof(char));
	while (i < len && ptr)
	{
		ptr[i] = str[i + start];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
