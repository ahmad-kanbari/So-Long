/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelpos.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akanbari <akanbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 07:44:39 by akanbari          #+#    #+#             */
/*   Updated: 2023/11/18 14:12:14 by akanbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

void	ft_lstdelpos(t_list **head, int position)
{
	t_list	*current;
	t_list	*prev;

	head = current;
	prev = head;
	if (*head == NULL)
		ft_printf("List is already empty");
	else if (position == 1)
	{
		*head = current->next;
		free(current);
		current = NULL;
	}
	else
	{
		while (position != 1)
		{
			prev = current;
			current = current->next;
			position--;
		}
		prev->next = current->next;
		free(current);
		current = NULL;
	}
}
