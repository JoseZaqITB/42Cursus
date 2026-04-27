/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoseyusprogrammer <yoseyusprogrammer@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 11:03:35 by yoseyusprog       #+#    #+#             */
/*   Updated: 2026/04/27 11:15:56 by yoseyusprog      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	if (size * nmemb > sizeof(int))
		return (0);
	if (size == 0 || nmemb == 0)
		return (malloc(0));
	return (malloc(size * nmemb));
}
