/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzaquina <jzaquina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 16:43:29 by jzaquina          #+#    #+#             */
/*   Updated: 2026/05/11 16:43:29 by jzaquina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	addstr(char	*ptr, char *str, int start)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ptr[start + i] = str[i];
		i++;
	}
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str1;
	char	*str2;
	char	*ptr;
	size_t	len1;
	size_t	len2;

	str1 = (char *)s1;
	str2 = (char *)s2;
	len1 = ft_strlen(str1);
	len2 = ft_strlen(str2);
	ptr = (char *)ft_calloc(len1 + len2 + 1, sizeof(char));
	if (!s1 || !s2 || !ptr)
		return (0);
	addstr(ptr, str1, 0);
	addstr(ptr, str2, len1);
	ptr[len1 + len2] = '\0';
	return (ptr);
}
