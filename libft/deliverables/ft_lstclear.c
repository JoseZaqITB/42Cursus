/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzaquina <jzaquina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 16:41:37 by jzaquina          #+#    #+#             */
/*   Updated: 2026/05/11 16:41:38 by jzaquina         ###   ########.fr       */
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
