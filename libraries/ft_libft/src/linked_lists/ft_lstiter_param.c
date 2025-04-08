/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_param.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akanbari <akanbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 21:36:53 by akanbari          #+#    #+#             */
/*   Updated: 2023/11/18 13:49:26 by akanbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter_param(t_list *lst, void (*f)(void *, void *), void *ptr)
{
	t_list	*temp;

	temp = lst;
	while (temp != NULL)
	{
		f(temp->content, ptr);
		temp = temp->next;
	}
}
