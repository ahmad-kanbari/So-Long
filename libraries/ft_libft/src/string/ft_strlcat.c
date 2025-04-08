/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akanbari <akanbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 21:20:18 by akanbari          #+#    #+#             */
/*   Updated: 2023/11/16 22:41:44 by akanbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dest_len;
	size_t	src_len;
	size_t	i;

	src_len = ft_strlen(src);
	if (dstsize == 0 && dst == NULL)
		return (src_len);
	dest_len = ft_strlen(dst);
	if (dest_len < dstsize && dstsize != 0)
	{
		i = 0;
		while ((dest_len + i) < (dstsize - 1) && src[i])
		{
			dst[dest_len + i] = src[i];
			i++;
		}
		if (i < dstsize)
			dst[dest_len + i] = '\0';
		return (dest_len + src_len);
	}
	return (dstsize + src_len);
}
