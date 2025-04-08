/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akanbari <akanbari@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 20:10:28 by akanbari          #+#    #+#             */
/*   Updated: 2023/09/29 15:08:28 by akanbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*head_tmp;

	if (!lst || !(*lst) || !del)
		return ;
	head_tmp = *lst;
	while (head_tmp != NULL)
	{
		head_tmp = head_tmp->next;
		del(head_tmp->content);
		free(*lst);
		*lst = head_tmp;
	}
	*lst = NULL;
}
