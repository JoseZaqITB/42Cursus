/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzaquina <jzaquina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 16:30:17 by jzaquina          #+#    #+#             */
/*   Updated: 2026/07/21 10:49:08 by jzaquina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

char	*read_and_stash(int fd, char *stash)
{
	char	*buffer;
	char	*temp;
	int		readcount;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (0);
	readcount = 1;
	while (readcount > 0 && !ft_strchr(stash, '\n'))
	{
		readcount = read(fd, buffer, BUFFER_SIZE);
		if (readcount == -1)
		{
			free(buffer);
			free(stash);
			return (0);
		}
		buffer[readcount] = '\0';
		temp = stash;
		stash = ft_strjoin(stash, buffer);
		free(temp);
	}
	free(buffer);
	return (stash);
}

char	*extract_line(char *stash)
{
	char	*line;
	int		i;

	i = 0;
	if (!stash || !stash[i])
		return (0);
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] == '\n')
		line = ft_substr(stash, 0, i + 1);
	else
		line = ft_substr(stash, 0, i);
	return (line);
}

char	*save_leftover(char *stash)
{
	char	*leftover;
	int		i;

	i = 0;
	if (!stash)
		return (0);
	while (stash[i] && stash[i] != '\n')
		i++;
	if (!stash[i] || !stash[i + 1])
	{
		free(stash);
		return (0);
	}
	leftover = ft_substr(stash, i + 1, ft_strlen(stash) - (i + 1));
	free(stash);
	return (leftover);
}

char	*get_next_line(int fd)
{
	static char	*leftover[1024];
	char		*line;

	if (fd < 0 || fd >= 1024 || BUFFER_SIZE <= 0)
		return (0);
	if (!leftover[fd])
	{
		leftover[fd] = malloc(sizeof(char) * 1);
		if (!leftover[fd])
			return (0);
		leftover[fd][0] = '\0';
	}
	leftover[fd] = read_and_stash(fd, leftover[fd]);
	if (!leftover[fd])
		return (0);
	line = extract_line(leftover[fd]);
	leftover[fd] = save_leftover(leftover[fd]);
	return (line);
}
