/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzaquina <jzaquina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 11:28:07 by yoseyusprog       #+#    #+#             */
/*   Updated: 2026/05/09 13:09:42 by jzaquina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	actualsize;

	if (!s)
		return (0);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	actualsize = ft_strlen(s + start);
	if (len > actualsize)
		len = actualsize;
	ptr = (char *)ft_calloc(len + 1, sizeof(char));
	if (!ptr)
		return (0);
	ft_strlcpy(ptr, s + start, len + 1);
	return (ptr);
}
