/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzaquina <jzaquina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 16:30:17 by jzaquina          #+#    #+#             */
/*   Updated: 2026/06/09 16:55:35 by jzaquina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

void	add_substr(char *tempbuff, char *buffer, int endindex)
{
	tempbuff = ft_substr(tempbuff, 0, endindex + 1);
	buffer = append_str(buffer, tempbuff);
}

char	*read_line(int fd)
{
	static char	tempbuff[BUFFER_SIZE];
	char		*buffer;
	int			break_index;
	int			len;
	int			readn;

	buffer = "";
	break_index = 0;
	len = 0;
	readn = 0;
	while (1)
	{
		buffer = append_str(buffer, tempbuff);
		readn = read(fd, tempbuff, BUFFER_SIZE);
		if (readn == 0 || readn == -1)
			break ;
		break_index = get_linebreak(tempbuff, BUFFER_SIZE);
		if (break_index != -1)
			break ;
		len += readn;
	}
	if (readn != 0 && readn != -1)
		add_substr(tempbuff, buffer, break_index);
	return (buffer);
}

char	*get_next_line(int fd)
{
	char		*line;

	line = read_line(fd);
	return (line);
}
