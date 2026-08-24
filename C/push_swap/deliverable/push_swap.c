#include <stdio.h>
#include <stddef.h>
#include <limits.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct s_flag
{
	char	*name;
	int	value;
} t_flag;

size_t	ft_strlen(const char *s1)
{
	size_t	i;

	i = 0;
	while (s1[i])
		i++;
	return (i);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (i < n && s1[i] && (s1[i] == s2[i]))
		i++;
	if (i == n)
		return (0);
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int	is_flag(char *argv, int *strat, int *bench)
{
	size_t	i;
	static const t_flag  lut[] = {
		{"--simple", 1},
		{"--medium", 2},
		{"--complex", 3},
		{"--adaptive", 4},
		{NULL, 0}
	};

	i = 0;
	if (ft_strncmp(argv, "--bench", 8) == 0)
	{
		*bench = 1;
		return (1);
	}
	while (lut[i].name != NULL)
	{
		if (ft_strncmp(argv, lut[i].name, ft_strlen(lut[i].name) + 1) == 0)
		{
			*strat = lut[i].value;
			return (1);
		}
		i++;
	}
	return (0);
}

int	ft_checkdig(const char *str, int sign, int *result)
{
	int	i;
	long	res;

	i = 0;
	res = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		res = (res * 10) + (str[i] - '0');
		if ((sign == 1 && res > INT_MAX) || (sign == -1 && res > (long)INT_MAX + 1))
			return (0);
		i++;
	}
	*result = (int)(res * sign);
	return (1);
}

int	ft_isnumber(const char *str, int *result)
{
	int	i;
	int	sign;

	sign = 1;
	i = 0;
	if (!str || !str[i])
		return (0);
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;	
		i++;
	}	
	if (!str[i])
		return (0);
	return (ft_checkdig(&str[i], sign, result));
}

//Split
static int	ft_countwords(const char *s, char c)
{
	int	count;
	int	word;

	count = 0;
	word = 0;
	while (*s)
	{
		if (*s != c && !word)
		{
			word = 1;
			count++;
		}
		else if (*s == c)
			word = 0;
		s++;
	}
	return (count);
}

void	ft_free_split(char **split)
{
	int	i;

	i = 0;
	if (!split)
		return ;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int	i;
	int	j;
	int	start;
	int	word_i;

	i = 0;
	word_i = 0;
	if (!s)
		return (NULL);
	res = malloc(sizeof(char *) * (ft_countwords(s, c) + 1));
	if (!res)
		return (NULL);
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (!s[i])
			break ;
		start = i;
		while (s[i] && s[i] != c)
			i++;
		res[word_i] = malloc(i - start + 1);
		j = 0;
		while (start < i)
		{
			res[word_i][j] = s[start];
			j++;
			start++;
		}
		res[word_i][j] = '\0';
		word_i++;
	}
	res[word_i] = NULL;
	return (res);
}

//Duplicados
int	ft_isduplicate(int *arr, int curr_size, int num)
{
	int	i;

	i = 0;
	while (i < curr_size)
	{
		if (arr[i] == num)
			return (1);
		i++;
	}
	return (0);
}

//Error}
void	ft_error(int *arr)
{
	if (arr)
		free(arr);
	write(2, "Error\n", 6);
	exit(1);
}

int	main(int argc, char **argv)
{
	int	strat;
	int	bench_mode;
	int	i;
	int	j;
	int	*final_array;
	int	total_numbers;
	int	parsed_value;
	char	**sub_args;

	strat = 4;
	bench_mode = 0;
	i = 1;
	j = 0;
	total_numbers = 0;
	final_array = malloc(sizeof(int) * (argc * 10));
	if (argc < 2)
	{
		free(final_array);
		return (0);
	}
	while (i < argc)
	{
		if (is_flag(argv[i], &strat, &bench_mode))
		{
			printf("[Bandera detectada] Argumento: %s -> Config. actualizada.\n", argv[i]);
			i++;
			continue ;
		}
		sub_args = ft_split(argv[i], ' ');
		if (!sub_args || !sub_args[0])
		{
			ft_free_split(sub_args);
			ft_error(final_array);
		}
		j = 0;
		while (sub_args[j])
		{
			if (!ft_isnumber(sub_args[j], &parsed_value))
			{
				ft_free_split(sub_args);
				ft_error(final_array);
			}
			if (ft_isduplicate(final_array, total_numbers, parsed_value))
			{
				ft_free_split(sub_args);
				ft_error(final_array);
			}
			final_array[total_numbers] = parsed_value;
			total_numbers++;
			j++;
		}
		ft_free_split(sub_args);
		i++;
	}
	printf("\n--- RESULTADO del PARSER ---\n");
	printf("Estrategia elegida: - %d - (1:simple, 2:medium, 3:complex, 4:adaptive)\n", strat);
	printf("Modo Benchmark activado: %s\n", bench_mode ? "Sí" : "No");
	printf("Array final (%d numeros): ", total_numbers);
	i = 0;
	while (i < total_numbers)
	{
		printf("[%d] ", final_array[i]);
		i++;
	}
	printf("\n");
	return (0);
}
