/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzaquina <jzaquina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 16:39:52 by jzaquina          #+#    #+#             */
/*   Updated: 2026/05/11 16:39:53 by jzaquina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	if (size > 0 && nmemb > (SIZE_MAX / size))
		return (0);
	if (size == 0 || nmemb == 0)
		return (malloc(0));
	ptr = malloc(size * nmemb);
	if (!ptr)
		return (0);
	ft_bzero(ptr, size * nmemb);
	return (ptr);
}
