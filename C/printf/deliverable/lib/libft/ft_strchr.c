/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzaquina <jzaquina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 16:43:13 by jzaquina          #+#    #+#             */
/*   Updated: 2026/05/11 16:43:13 by jzaquina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	unsigned char	chr;
	char			*str;

	str = (char *)s;
	chr = (unsigned char)c;
	while (1)
	{
		if (*str == chr)
			return (str);
		if (!*str)
			return (0);
		str++;
	}
	return (0);
}
