/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoseyusprogrammer <yoseyusprogrammer@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 17:21:07 by yoseyusprog       #+#    #+#             */
/*   Updated: 2026/04/30 17:59:08 by yoseyusprog      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*currlist;
	t_list	*nextlist;

	currlist = *lst;
	nextlist = currlist;
	while (nextlist)
	{
		currlist = nextlist;
		(*del)((currlist)->content);
		nextlist = (currlist)->next;
		free(currlist);
	}
	*lst = 0;
}
