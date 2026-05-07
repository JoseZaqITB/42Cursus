/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoseyusprogrammer <yoseyusprogrammer@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 12:07:50 by yoseyusprog       #+#    #+#             */
/*   Updated: 2026/05/07 17:12:20 by yoseyusprog      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned char	chr;
	char			*str;
	int				i;

	chr = (unsigned char)c;
	str = (char *)s;
	i = ft_strlen(s) + 1;
	while (i--)
	{
		if (str[i] == chr)
			return (str + i);
	}
	return (0);
}
