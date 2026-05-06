/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoseyusprogrammer <yoseyusprogrammer@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 15:27:12 by yoseyusprog       #+#    #+#             */
/*   Updated: 2026/04/24 15:42:11 by yoseyusprog      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	char	*str;

	str = (char *)s;
	while (1)
	{
		if (*str == c)
			return (str);
		if (!*str)
			return (0);
		str++;
	}
	return (0);
}
