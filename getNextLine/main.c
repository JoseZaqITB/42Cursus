
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include "get_next_line.h"

void	readlines(int fd)
{
	char	*line;

	printf("fd: %d\n", fd);
	line = "";
	while (line)
	{
		// scanf("%d", &in);
		printf("|%s|", line);
		if (line != "")
			free(line);
		line = get_next_line(fd);
	}
	free(line);
}

void	testall(void)
{
	int		fd;

	fd = open("./testall.txt", O_RDWR);
	readlines(fd);
	close(fd);
}

void	testnl(void)
{
	int		fd;

	fd = open("./nl.txt", O_RDWR);
	readlines(fd);
	close(fd);
}

void	testnonl()
{
	int		fd;

	fd = open("./43_no_nl.txt", O_RDWR);
	readlines(fd);
	close(fd);
}

int	main(void)
{
	int	in;

	while (1)
	{
		printf(
			"---MAIN MENU---\n"
			"1. Leer todo un archivo\n"
			"2. Leer un \\n\n"
			"3. Leer una sola linea\n"
			"0. end\n"
			);
		scanf("%d", &in);
		printf("\n||---------------\n\n");
		if (in == 1)
			testall();
		else if (in == 2)
			testnl();
		else if (in == 3)
			testnonl();
		else if (in == 0)
			return (0);
		else
		{
			printf("Incorrect selection");
			return (0);
		}
		printf("\n\n||---------------\n");
	}
	return (0);
}
