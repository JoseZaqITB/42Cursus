/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzaquina <jzaquina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 16:13:38 by jzaquina          #+#    #+#             */
/*   Updated: 2026/04/23 16:19:13 by jzaquina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

int	main(void)
{
	int	res = ft_isalpha('c');

	printf("%d", res);
	res = ft_isalpha('A');
	printf("%d", res);
	res = ft_isalpha('>');
	printf("%d", res);

}
