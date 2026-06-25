/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzaquina <jzaquina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 16:30:17 by jzaquina          #+#    #+#             */
/*   Updated: 2026/06/25 19:08:17 by jzaquina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*readline(int fd)
{
	char	buffer[BUFFER_SIZE + 1];
	int		readcount;

	readcount = read(fd, buffer, BUFFER_SIZE);
	if (readcount <= 0)
		return (0);
	buffer[readcount] = '\0';
	return (ft_strjoin("", &buffer[0]));
}

int	get_breakline(const char *s)
{
	char	*str;
	int		i;

	str = (char *)s;
	i = 0;
	while (1)
	{
		if (str[i] == '\n')
			break ;
		if (!str[i++])
			return (-1);
	}
	return (i);
}

int	readbreakline(int fd, char **s)
{
	char		*buffer;
	int			breakpos;
	int			curpos;
	int			i;
	char		*temp;

	curpos = 0;
	breakpos = 0;
	buffer = ft_strjoin("",*s);
	while (1)
	{
		curpos = get_breakline(buffer);
		i = ft_strlen(buffer);
		free(buffer);
		if (curpos != -1)
			return (breakpos + curpos);
		breakpos += i;
		buffer = readline(fd);
		if (!buffer)
			return (-1);
		temp = *s;
		*s = ft_strjoin(*s, buffer);
		free(temp);
	}
	return (breakpos);
}

char	*ft_substr_from(char *s, int start)
{
	if (!s || s[0] == '\0')
		return (0);
	return (ft_substr(s, start, ft_strlen(s) - start));
}

char	*get_next_line(int fd)
{
	static char	*leftover;
	char		*tempbuffer;
	int			breakpos;
	char		*line;

	line = 0;
	if (!leftover || leftover[0] == '\0')
	{
		tempbuffer = readline(fd);
		if (!tempbuffer)
		{
			free(leftover);
			leftover = 0;
			return (0);
		}
	}
	else
		tempbuffer = leftover;
	breakpos = readbreakline(fd, &tempbuffer);
	line = ft_substr(tempbuffer, 0, breakpos);
	leftover = ft_substr_from(tempbuffer, breakpos + 1);
	free(tempbuffer);
	return (line);
}
