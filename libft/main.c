/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoseyusprogrammer <yoseyusprogrammer@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 16:13:38 by jzaquina          #+#    #+#             */
/*   Updated: 2026/04/24 11:44:42 by yoseyusprog      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

void	testft(char *title, char c1, char c2, int (*f)(int));

int	main(void)
{
	char	c1 = 'a';
	char	c2 = '0';

	testft("is ascii?", c1, c2, ft_isalpha);
	testft("is ascii?", c1, c2, ft_isdigit);
	testft("is ascii?", c1, c2, ft_isalnum);
	testft("is ascii?", c1, 200, ft_isascii);
	testft("is printable?", 31, ' ', ft_isprint);

	int	res = 0;
	// lenght of a string
	char *s1 = "oli";
	char *s2 = "chai";
	printf("\nlength of a string(%s, %s): \n", s1, s2);
	res = ft_strlen(s1);
	printf("|%d|", res);
	res = ft_strlen(s2);
	printf("|%d|", res);
}

void	testft(char *title, char c1, char c2, int (*f)(int))
{
	int	res = 0;

	printf("\n%s (%c, %c): \n", title, c1, c2);
	res = (*f)(c1);
	printf("|%d|", res);
	res = (*f)(c2);
	printf("|%d|", res);
}
