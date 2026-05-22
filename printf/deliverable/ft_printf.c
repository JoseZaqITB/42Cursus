/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzaquina <jzaquina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 17:58:29 by jzaquina          #+#    #+#             */
/*   Updated: 2026/05/22 11:44:19 by jzaquina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

int	ft_printf(char const *s, char *args[])
{
	char *s2 = ft_substr(s, 2, 4);
	printf("%s, %s", s2, args[0]);
	return (0);
}
