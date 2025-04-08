/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akanbari <akanbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 16:08:36 by akanbari          #+#    #+#             */
/*   Updated: 2023/11/16 22:16:24 by akanbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*head_lst;
	t_list	*temp;

	if (!lst || !f || !del)
		return (NULL);
	head_lst = NULL;
	while (lst != NULL)
	{
		temp = ft_lstnew((*f)(lst->content));
		if (!temp)
		{
			ft_lstclear(&head_lst, del);
		}
		ft_lstadd_back(&head_lst, temp);
		lst = lst->next;
	}
	return (head_lst);
}
