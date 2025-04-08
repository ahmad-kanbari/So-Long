/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstreverse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akanbari <akanbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 15:45:14 by akanbari          #+#    #+#             */
/*   Updated: 2023/11/16 22:19:33 by akanbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstreverse(t_list **lst)
{
	t_list	*prev;
	t_list	*next;

	prev = NULL;
	next = NULL;
	while (*lst != NULL)
	{
		next = (*lst)->next;
		(*lst)->next = prev;
		prev = (*lst);
		*lst = next;
	}
	*lst = prev;
	return (*lst);
}
