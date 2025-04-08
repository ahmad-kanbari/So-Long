/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstprint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akanbari <akanbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 15:00:07 by akanbari          #+#    #+#             */
/*   Updated: 2023/11/18 14:13:42 by akanbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

void	ft_lstprint(t_list *ptr)
{
	int	i;

	i = 0;
	if (!ptr)
	{
		ft_printf("The Linked Lists is empty");
		return ;
	}
	while (ptr != NULL)
	{
		ft_printf("node : %d , content :%s\n", i, ptr->content);
		i++;
		ptr = ptr->next;
	}
}
