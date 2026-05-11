/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzaquina <jzaquina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 16:43:49 by jzaquina          #+#    #+#             */
/*   Updated: 2026/05/11 16:43:49 by jzaquina         ###   ########.fr       */
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
	mappedstr = (char *)ft_calloc(len + 1, sizeof(char));
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
