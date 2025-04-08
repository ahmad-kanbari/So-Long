/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akanbari <akanbari@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 18:46:28 by akanbari          #+#    #+#             */
/*   Updated: 2023/09/29 21:38:44 by akanbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	n_count;

	n_count = 0; 
	if (lst == NULL)
		return (0);
	while (lst != NULL)
	{
		n_count++;
		lst = lst->next;
	}
	return (n_count);
}
