/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akanbari <akanbari@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 18:28:11 by akanbari          #+#    #+#             */
/*   Updated: 2023/09/29 21:42:49 by akanbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*ptr;

	ptr = s;
	while (n-- > 0)
	{
		if (*ptr == (unsigned char )c)
			return ((void *)ptr);
		ptr++;
	}
	return (NULL);
}
//memchr locates the first occurrence of c;