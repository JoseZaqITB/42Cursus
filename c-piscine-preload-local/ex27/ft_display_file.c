/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzaquina <jzaquina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 11:25:09 by jzaquina          #+#    #+#             */
/*   Updated: 2026/04/23 12:32:42 by jzaquina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

void	ft_putstr(char *str, int fildes)
{
	int	length;

	length = ft_strlen(str);
	write(fildes, str, length);
}

int	print_file(char *path)
{
	char	*error;
	char	buffer[101];
	int		ft;
	int		read_bytes;

	error = "Cannot read file.\n";
	ft = open(path, O_RDWR);
	if (ft == -1)
	{
		ft_putstr(error, 2);
		return (1);
	}
	read_bytes = read(ft, buffer, 100);
	if (read_bytes == -1)
	{
		ft_putstr(error, 2);
		return (1);
	}
	buffer[read_bytes] = '\0';
	close(ft);
	ft_putstr(buffer, 1);
	return (0);
}

int	main(int argc, char *argv[] )
{
	char	*many_arg;
	char	*no_arg;
	int		res;

	many_arg = "Too many arguments.\n";
	no_arg = "File name missing.\n";
	if (argc == 1)
	{
		ft_putstr(no_arg, 2);
		return (1);
	}
	else if (argc != 2)
	{
		ft_putstr(many_arg, 2);
		return (1);
	}
	res = print_file(argv[1]);
	return (res);
}
