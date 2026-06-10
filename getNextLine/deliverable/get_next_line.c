/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzaquina <jzaquina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 16:30:17 by jzaquina          #+#    #+#             */
/*   Updated: 2026/06/10 20:09:06 by jzaquina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>


char	*get_next_line(int fd)
{
	static char	*leftover;
	char		buffer[BUFFER_SIZE];

	int	breakpos;

	breakpos = -1;
	// if buffer is not empty, play with it
	// if not, read a new bunch of bytes and play with them

	// 1. read() / getbreaklinefrombuffer()
	if (!leftover)
	{
		read(fd, buffer, BUFFER_SIZE);
		leftover = &buffer[0];
	}
	printf("--%s--", leftover);
	// 2. get_breakline()
	breakpos = ft_strchrn(leftover, '\n');
	// 3. appendleftover()
	// 4. saveleftover()
	// 5. return_line()
	return "";
}
