/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzaquina <jzaquina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 16:44:15 by jzaquina          #+#    #+#             */
/*   Updated: 2026/05/11 16:44:16 by jzaquina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int	i;

	while (ft_strchr(set, *s1) && *s1)
		s1++;
	i = ft_strlen(s1) - 1;
	while (ft_strchr(set, s1[i]) && i)
		--i;
	return (ft_substr(s1, 0, i + 1));
}
