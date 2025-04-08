/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akanbari <akanbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 22:22:56 by akanbari          #+#    #+#             */
/*   Updated: 2023/11/16 22:23:46 by akanbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_malloc(size_t size)
{
	void	*ptr;

	ptr = (void *)malloc(size);
	if (!ptr)
	{
		write(1, "ERROR - returning null", 22);
		return (NULL);
	}
	return (ptr);
}
