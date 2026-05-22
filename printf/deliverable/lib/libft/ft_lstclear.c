/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzaquina <jzaquina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 16:41:37 by jzaquina          #+#    #+#             */
/*   Updated: 2026/05/11 18:38:58 by jzaquina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*currlist;
	t_list	*nextlist;

	currlist = *lst;
	nextlist = currlist;
	if (!lst || !del)
		return ;
	while (nextlist)
	{
		currlist = nextlist;
		nextlist = (currlist)->next;
		ft_lstdelone(currlist, del);
	}
	*lst = 0;
}
