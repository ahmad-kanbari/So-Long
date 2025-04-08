/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_cmp.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akanbari <akanbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 21:40:51 by akanbari          #+#    #+#             */
/*   Updated: 2023/11/16 22:10:00 by akanbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front_cmp(t_list **lst, t_list *new, \
		int (*cmp)(void *, void *))
{
	t_list	*n;

	if (lst == NULL || *lst == NULL)
	{
		ft_lstadd_front(lst, new);
		return ;
	}
	if (cmp((*lst)->content, new->content) > 0)
		ft_lstadd_front(lst, new);
	else if ((*lst)->next == NULL)
		ft_lstadd_back(lst, new);
	else
	{
		n = *lst;
		while (n->next != NULL)
		{
			if (cmp((n->next)->content, new->content) > 0)
				break ;
			n = n->next;
		}
		new->next = n->next;
		n->next = new;
	}
}
