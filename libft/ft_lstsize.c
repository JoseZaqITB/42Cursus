/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoseyusprogrammer <yoseyusprogrammer@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 19:21:41 by yoseyusprog       #+#    #+#             */
/*   Updated: 2026/04/29 19:26:48 by yoseyusprog      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	ft_lstsize(t_list *lst)
{
	int	nnode;

	nnode = 0;
	printf("%s", (char *)lst->content);
	while (lst)
	{
		lst = lst->next;
		nnode++;
	}

	return (nnode);
}
