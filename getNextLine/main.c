
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include "get_next_line.h"

void	testall(void)
{
	char	*line;
	int		fd;
	int		in;


	fd = open("./testall.txt", O_RDWR);
	printf("fd: %d\n", fd);
	while (line)
	{
		scanf("%d", &in);
		line = "";
		line = get_next_line(fd);
		printf("|%s|\n", line);
	}
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
			"0. end\n"
			);
		scanf("%d", &in);
		printf("\n||---------------\n\n");
		if (in == 1)
			testall();
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
