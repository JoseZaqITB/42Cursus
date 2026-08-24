/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoseyusprogrammer <yoseyusprogrammer@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 15:28:38 by yoseyusprog       #+#    #+#             */
/*   Updated: 2026/04/17 15:50:01 by yoseyusprog      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*numbers;
	int	i;
	int	n;

	if (min >= max)
		return (NULL);
	numbers = malloc((max - min) * sizeof(int));
	if (!numbers)
		return (NULL);
	i = 0;
	n = min;
	while (n < max)
	{
		numbers[i] = n;
		i++;
		n++;
	}
	return (numbers);
}
/*
#include <stdio.h>

int	main(void)
{
	int min = -2;
	int max = 0;
	int *numbers = ft_range(min, max);

	for (int i = min; i < max; i++)
	{
		printf("%d", numbers[i - min]);
	}

	free(numbers);
	numbers = NULL;

	return (0);
}
*/
