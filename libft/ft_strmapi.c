/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoseyusprogrammer <yoseyusprogrammer@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 11:56:20 by yoseyusprog       #+#    #+#             */
/*   Updated: 2026/04/28 12:03:33 by yoseyusprog      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*mappedstr;
	char	*str;
	int		len;
	int		i;

	i = 0;
	str = (char *)s;
	len = ft_strlen(str);
	mappedstr = calloc(len + 1, sizeof(char));
	if (!mappedstr)
		return (0);
	mappedstr[len] = '\0';

	while (str[i])
	{
		mappedstr[i] = (*f)(i, str[i]);
		i++;
	}
	return (mappedstr);
}
