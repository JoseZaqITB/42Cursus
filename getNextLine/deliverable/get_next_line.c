/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzaquina <jzaquina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 16:30:17 by jzaquina          #+#    #+#             */
/*   Updated: 2026/06/11 21:09:49 by jzaquina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	get_breakline(const char *s)
{
	char	*str;
	char	**res;
	int		i;

	str = (char *)s;
	while (1)
	{
		if (*str == '\n')
			break ;
		if (!*str)
			return (-1);
		str++;
		i++;
	}
	return (i);
}

int	readbreakline(int fd, char **s)
{
	char		buffer[BUFFER_SIZE];
	int			breakpos;
	int			curpos;
	int			i;

	curpos = 0;
	breakpos = 0;
	i = -1;
	while ((*s)[++i])
		buffer[i] = (*s)[i];
	while (1)
	{
		curpos = get_breakline(buffer);
		if (curpos != -1)
		{
			printf("%d", curpos);
			return (breakpos + curpos);
		}
		breakpos += ft_strlen(buffer);
		if (read(fd, buffer, BUFFER_SIZE) <= 0)
			return (-1);
		*s = ft_strjoin(*s, buffer);
	}
	return (breakpos);
}

char	*get_next_line(int fd)
{
	static char	*leftover;
	char		*tempbuffer;
	char		buffer[BUFFER_SIZE];

	int		breakpos;
	char	*line;

	line = 0;
	breakpos;
	// if buffer is not empty, play with it
	// if not, read a new bunch of bytes and play with them

	// 1. read() / getbreaklinefrombuffer()
	if (!leftover)
	{
		if (read(fd, buffer, BUFFER_SIZE) <= 0)
			return (0);
		tempbuffer = &buffer[0];
	}
	// 2. readbreakline()/get_breakline()
	breakpos = readbreakline(fd, &tempbuffer);
	printf("break: %d, tempBuffer: %s", breakpos, tempbuffer);
	// 3. appendleftover()
	tempbuffer = ft_strjoin(leftover, tempbuffer);
	// 5. return_line()
	line = ft_substr(tempbuffer, 0, breakpos);
	// 4. saveleftover()
	leftover = ft_substr(tempbuffer, breakpos + 1, ft_strlen(tempbuffer) - (breakpos + 1));
	return (line);
}
