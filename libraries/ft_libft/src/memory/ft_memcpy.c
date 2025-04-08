/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akanbari <akanbari@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 20:28:54 by akanbari          #+#    #+#             */
/*   Updated: 2023/09/29 21:43:45 by akanbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*support_dest;
	const unsigned char	*support_source;

	if (n == 0)
		return (dst);
	support_dest = dst;
	support_source = src;
	if (src == 0 && dst == 0)
		return (NULL);
	i = 0;
	while (i < n)
	{
		support_dest[i] = support_source[i];
		i++;
	}
	return (dst);
}
