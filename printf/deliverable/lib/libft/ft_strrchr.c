/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzaquina <jzaquina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 16:44:08 by jzaquina          #+#    #+#             */
/*   Updated: 2026/05/11 16:44:08 by jzaquina         ###   ########.fr       */
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
