/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akanbari <akanbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 21:39:27 by akanbari          #+#    #+#             */
/*   Updated: 2023/11/18 13:49:50 by akanbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*m_merge(t_list *a, t_list *b, \
		int (*cmp)(void *, void *))
{
	t_list	*result;

	result = NULL;
	if (a == NULL)
		return (b);
	else if (b == NULL)
		return (a);
	if (cmp(a->content, b->content) > 0) 
	{
		result = a;
		result->next = m_merge(a->next, b, cmp);
	}
	else 
	{
		result = b;
		result->next = m_merge(a, b->next, cmp);
	}
	return (result);
}

static void	m_split(t_list *source, t_list **frontRef, t_list **backRef)
{
	t_list	*fast;
	t_list	*slow;

	slow = source;
	fast = source->next;
	while (fast != NULL)
	{
		fast = fast->next;
		if (fast != NULL)
		{
			slow = slow->next;
			fast = fast->next;
		}
	}
	*frontRef = source;
	*backRef = slow->next;
	slow->next = NULL;
}

/**
 * MERGE SORT
 **/
void	ft_lstsort(t_list **lst, int (*cmp)(void *, void *))
{
	t_list	*head;
	t_list	*a;
	t_list	*b;

	head = *lst;
	if ((head == NULL) || (head->next == NULL))
		return ;
	m_split(head, &a, &b);
	ft_lstsort(&a, cmp);
	ft_lstsort(&b, cmp);
	*lst = m_merge(a, b, cmp);
}
