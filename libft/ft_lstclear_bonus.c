/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacattan <gacattan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 11:05:43 by gacattan          #+#    #+#             */
/*   Updated: 2025/11/12 12:01:19 by gacattan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;
	t_list	*temp2;

	if (!lst || !del)
		return ;
	temp2 = *lst;
	while (temp2 != NULL)
	{
		temp = temp2->next;
		ft_lstdelone(temp2, del);
		temp2 = temp;
	}
	*lst = NULL;
}
