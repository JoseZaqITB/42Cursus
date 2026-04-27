/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoseyusprogrammer <yoseyusprogrammer@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 11:22:54 by yoseyusprog       #+#    #+#             */
/*   Updated: 2026/04/27 11:23:02 by yoseyusprog      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


char	*ft_strdup(char *src)
{
	char	*dpsrc;
	int		length;
	int		i;

	length = sizeof(char);
	i = 0;
	while (src[i])
	{
		length += sizeof(char);
		i++;
	}
	i = 0;
	dpsrc = malloc(length);
	if (!dpsrc)
		return (0);
	while (src[i])
	{
		dpsrc[i] = src[i];
		i++;
	}
	dpsrc[i] = '\0';
	return (dpsrc);
}
