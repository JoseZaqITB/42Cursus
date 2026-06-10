/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzaquina <jzaquina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 16:30:17 by jzaquina          #+#    #+#             */
/*   Updated: 2026/06/10 21:11:07 by jzaquina         ###   ########.fr       */
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
			return (0);
		str++;
		i++;
	}
	return (i);
}

char	*get_next_line(int fd)
{
	static char	*leftover;
	char		*tempbuffer;
	char		buffer[BUFFER_SIZE];

	int	breakpos;
	char	*line;

	line = 0;
	breakpos;
	// if buffer is not empty, play with it
	// if not, read a new bunch of bytes and play with them

	// 1. read() / getbreaklinefrombuffer()
	if (!leftover)
	{
		read(fd, buffer, BUFFER_SIZE);
		tempbuffer = &buffer[0];
	}
	printf("--%s--", tempbuffer);
	// 2. get_breakline()
	breakpos = get_breakline(tempbuffer);

	// 3. appendleftover()
	tempbuffer = ft_strjoin(leftover, tempbuffer);
	// 5. return_line()
	line = ft_substr(tempbuffer, 0, breakpos);
	// 4. saveleftover()
	leftover = ft_substr(tempbuffer, breakpos + 1, ft_strlen(tempbuffer) - (breakpos + 1));
	return line;
}
