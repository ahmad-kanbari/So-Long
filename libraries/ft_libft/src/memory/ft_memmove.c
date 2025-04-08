/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akanbari <akanbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 23:54:16 by akanbari          #+#    #+#             */
/*   Updated: 2023/11/16 22:24:04 by akanbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*support_dest;
	const unsigned char	*support_source;

	if (len == 0)
		return (dst);
	if (src == 0 && dst == 0)
		return (NULL);
	support_dest = dst;
	support_source = src;
	if (dst > src)
	{
		while (len > 0)
		{
			support_dest[len - 1] = support_source[len - 1];
			len--;
		}
	}
	else
	{
		while (len-- > 0)
			*(support_dest++) = *(support_source++);
	}
	return (dst);
}
