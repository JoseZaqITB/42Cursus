/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoseyusprogrammer <yoseyusprogrammer@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 19:37:58 by yoseyusprog       #+#    #+#             */
/*   Updated: 2026/05/06 18:24:17 by yoseyusprog      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

t_list	*ft_lstlast(t_list *lst)
{
	while (lst->next)
	{
		lst = lst->next;
	}
	return (lst);
}
