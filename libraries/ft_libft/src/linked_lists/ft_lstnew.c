/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akanbari <akanbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 17:10:43 by akanbari          #+#    #+#             */
/*   Updated: 2023/11/16 22:16:28 by akanbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*n_ptr;

	n_ptr = (t_list *)malloc(sizeof(t_list));
	if (!n_ptr)
		return (NULL);
	n_ptr->content = content;
	n_ptr->next = NULL;
	return (n_ptr);
}
