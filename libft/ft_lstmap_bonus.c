/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacattan <gacattan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 13:20:01 by gacattan          #+#    #+#             */
/*   Updated: 2025/11/13 12:50:03 by gacattan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*copy;
	t_list	*first_node;

	if (!lst || !f || !del)
		return (NULL);
	first_node = ft_lstnew(f(lst->content));
	if (!first_node)
		return (NULL);
	lst = lst->next;
	while (lst)
	{
		copy = ft_lstnew(f(lst->content));
		if (!copy)
		{
			ft_lstclear(&first_node, del);
			return (NULL);
		}
		ft_lstadd_back(&first_node, copy);
		lst = lst->next;
		copy = copy->next;
	}
	return (first_node);
}
