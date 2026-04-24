/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoseyusprogrammer <yoseyusprogrammer@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 16:13:38 by jzaquina          #+#    #+#             */
/*   Updated: 2026/04/24 10:21:23 by yoseyusprog      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

int	main(void)
{
	int	res = ft_isalpha('c');

	printf("%d", res);
	res = ft_isalpha('A');
	printf("%d", res);
	res = ft_isalpha('>');
	printf("%d", res);

	// is digit
	printf("\nis digit: \n");
	res = ft_isdigit('0');
	printf("|%d|", res);
	res = ft_isdigit('a');
	printf("|%d|", res);
}
