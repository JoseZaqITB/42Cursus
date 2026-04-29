/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoseyusprogrammer <yoseyusprogrammer@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 16:13:38 by jzaquina          #+#    #+#             */
/*   Updated: 2026/04/29 19:02:15 by yoseyusprog      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"
#include <fcntl.h>

void	testft(char *title, char c1, char c2, int (*f)(int));

char	fn(unsigned int i, char c)
{
	return (c + i / 5);
};


void	fn2(unsigned int i, char *c)
{
	*c += i;
}

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

	// get pointer of the last char in s
	char 	*s9 = "wiiws";
	printf("\n get pointer of the last |%c| in |%s|\n", c3, s9);
	ptr= ft_strrchr(s9,c3);
	printf("|%s|", ptr);

	// compare two strings until n
	s8 = "aaa";
	s9 = "aab";
	int	n = 4;
	printf("\n compare two strings until |%d|: (|%s|%s|)\n", n, s8, s9);
	res = ft_strncmp(s8, s9, n);
	printf("|%d|", res);

	// get pointer of the first char in s
	n  = 4;
	printf("\n get pointer of the first |%c| in  the first %d bytes of |%s|\n", c3, n, s3);
	ptr= ft_memchr(s3,c3, n);
	printf("|%s|", ptr);

	// compare two memory areas until n
	s8 = "aabaacdd";
	s9 = "aab";
	n = 9;
	printf("\n compare two memory areas until |%d|: (|%s|%s|)\n", n, s8, s9);
	res = ft_memcmp(s8, s9, n);
	printf("|%d|", res);

	// search for a substring until n
	s8 = "aabaacdd";
	s9 = "aba";
	n = 4;
	printf("\n search for a substring until |%d|: (|%s|%s|)\n", n, s8, s9);
	s7 = ft_strnstr(s8, s9, n);
	printf("|%s|", s7);

	// allocate memory with calloc
	// todo

	//strdup
	char	*src = "perro con sarna y soda";
	char	*dpsrc = ft_strdup(src);
	printf("\n duplicate string: (|%s|)\n",src);

	printf("\nduplicated: |%s|\n", dpsrc);

	free(dpsrc);
	dpsrc = NULL;

	// create a substring
	printf("\nCreate a substring from |%s| starting at |%d| with size |%d|\n",src, 5, 10);
	s7 = ft_substr(src, 5, 10);
	printf("\n SUBSTR: |%s|\n", s7);

	// create a substring
	printf("\nCreate a string that appends |%s| |%s|\n",s8,s9);
	s7 = ft_strjoin(s8, s9);
	printf("\n new String: |%s|\n", s7);

	//
	s9 = "ab";
	printf("\nCreate a string that copy |%s| deleting all |%s|\n",src,s9);
	s7 = ft_strtrim(src, s9);
	printf("\n new String: |%s|\n", s7);

	//
	s8 = "-Hola-perro--sofa---maria---";
	c1 = '-';
	printf("\nSplit a string |%s| with delimeter |%c|\n",s8,c1);
	char **list = ft_split(s8, c1);
	while (*list)
	{
		printf("|%s|\n",*list);
		list++;
	}
	//
	n = -1234128391;
	printf("\nCreate a string of a number |%d|\n",n);
	s7 = ft_itoa(n);
	printf("\n Number String: |%s|\n", s7);
	//
	printf("\nMapped a string |%s|\n",s8);
	s7 = ft_strmapi(s8, &fn);
	printf("\n Mapped String: |%s|\n", s7);

	//
	printf("\nIterate and apply a function |%s|\n",str);
	ft_striteri(str, &fn2);
	printf("\n Iterated String: |%s|\n", str);

	//
	printf("\nAdd a char using a file descriptor |%c|\n",c1);
	ft_putchar_fd(c1, 1);

	//
	printf("\nAdd a string using a file descriptor |%s|\n",s8);
	ft_putstr_fd(s8, 1);

	//
	printf("\nAdd a string + new line using a file descriptor |%s|\n",s9);
	printf("|");
	ft_putendl_fd(s9, 1);
	printf("|");

	//
	printf("\nAdd a number + new line using a file descriptor |%s|\n",s9);
	printf("|");
	ft_putnbr_fd(n, 1);
	printf("|");

	/* LISTAS ENLAZADAS */
	printf("\n***** LISTAS ENLAZADAS *****\n");
	//
	printf("\ncreate a new node with this content |%s|\n",s8);
	t_list *nodeptr = ft_lstnew(s8);
	printf("content: %s", (char *)nodeptr->content);
	printf("\nnext: %s", (char *)nodeptr->next);
	//
	printf("\nAdd a new node with this content: |%s|. And loop the list \n",s9);
	t_list *nodeptr2 = ft_lstnew(s9);
	ft_lstadd_front(&nodeptr, nodeptr2);
	while (nodeptr)
	{
		printf("\ncontent: %s", (char *)nodeptr->content);
		//printf("\nnext: %s", (char *)nodeptr->next->content);
		nodeptr = nodeptr->next;
	}
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
