/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoseyusprogrammer <yoseyusprogrammer@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 15:27:12 by yoseyusprog       #+#    #+#             */
/*   Updated: 2026/05/07 17:08:25 by yoseyusprog      ###   ########.fr       */
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
