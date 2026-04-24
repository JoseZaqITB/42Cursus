/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoseyusprogrammer <yoseyusprogrammer@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 16:13:38 by jzaquina          #+#    #+#             */
/*   Updated: 2026/04/24 15:43:00 by yoseyusprog      ###   ########.fr       */
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

	// change first n bytes with c
	char	s3[] = "Oliwis"; // if using char *s3, it will be read-only string, it can not be modified
	printf("\n change first 3 bytes with $ (%s): \n", s3);
	ft_memset(s3, '$', 3);
	printf("|%s|", s3);

	// change first n bytes with c
	char	s4[] = "Oliwis";
	printf("\n change first 4 bytes with \\0 (%s): \n", s4);
	ft_bzero(s4, 4);
	printf("|%s|", s4);

	// change first n bytes with c
	char	s5[] = "Oliwis";
	char	s6[] = "NoOneHere";
	printf("\n copies the first 2 bytes of (%s) in (%s): \n", s5, s6);
	ft_memcpy(s6, s5, 2);
	printf("|%s|", s5);
	printf("|%s|", s6);

	// change first n bytes with c when overlap
	char	str[] = "Oliwis";
	char	*s7 = str;
	char	*s8 = str + 1;
	printf("\n copies the first 2 bytes of (%s) in (%s): \n", s7, s8);
	ft_memmove(s8, s7, 2);
	printf("|%s|", s7);
	printf("|%s|", s8);

	// to upper
	char c3 = 'w';
	printf("\n change |%c| to upper version\n", c3);
	c3 = ft_toupper(c3);
	printf("|%c|", c3);
	// to lower
	printf("\n change |%c| to upper version\n", c3);
	c3 = ft_tolower(c3);
	printf("|%c|", c3);

	// get pointer of the first char in s
	printf("\n get pointer of the first |%c| in |%s|\n", c3, s3);
	char *ptr= ft_strchr(s3,c3);
	printf("|%s|", ptr);
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
