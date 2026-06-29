/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzaquina <jzaquina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 16:30:17 by jzaquina          #+#    #+#             */
/*   Updated: 2026/06/29 19:30:26 by jzaquina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*readline(int fd)
{
	char	*buffer;
	int		readcount;
	char	*temp;

	buffer = malloc(1 * (BUFFER_SIZE + 1));
	readcount = read(fd, buffer, BUFFER_SIZE);
	if (readcount <= 0)
	{
		free(buffer);
		return (0);
	}
	buffer[readcount] = '\0';
	temp = ft_strjoin("", buffer);
	free(buffer);
	return (temp);
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

char	*ft_substr_from(char src[], char *s, int start)
{
	char	*temp;
	int		i;

	i = 0;
	if (!s || s[0] == '\0')
		return (0);
	temp = ft_substr(s, start, ft_strlen(s) - start);
	while (temp[i] && i < 1023)
	{
		src[i] = temp[i];
		i++;
	}
	src[i] = '\0';
	free(temp);
	return (s);
}

char	*get_next_line(int fd)
{
	static char	leftover[1024];
	char		*tempbuffer;
	int			breakpos;
	char		*line;

	if (leftover[0] == '\0')
	{
		tempbuffer = readline(fd);
		if (!tempbuffer)
			return (0);
	}
	else
		tempbuffer = ft_strjoin("", leftover);
	breakpos = readbreakline(fd, &tempbuffer);
	if (breakpos == -1)
	{
		leftover[0] = 0;
		return (tempbuffer);
	}
	line = ft_substr(tempbuffer, 0, breakpos + 1);
	ft_substr_from(leftover, tempbuffer, breakpos + 1);
	free(tempbuffer);
	return (line);
}
