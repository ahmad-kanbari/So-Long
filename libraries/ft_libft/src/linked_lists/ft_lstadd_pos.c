/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_pos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akanbari <akanbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 15:21:01 by akanbari          #+#    #+#             */
/*   Updated: 2023/11/18 14:12:09 by akanbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//aading after pos , starting from 1 , where position 3 is node 3 in list
void	ft_lstadd_pos_after(t_list **lst, t_list *new, \
		int position)
{
	t_list	*tmp;

	tmp = *lst;
	position--;
	while (position != 1)
	{
		tmp = tmp->next;
		position--;
	}
	new->next = tmp->next;
	tmp->next = new; 
}
