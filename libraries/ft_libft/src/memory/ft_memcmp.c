/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akanbari <akanbari@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 20:33:12 by akanbari          #+#    #+#             */
/*   Updated: 2023/09/29 21:43:14 by akanbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*temp1;
	const unsigned char	*temp2;

	temp1 = s1;
	temp2 = s2;
	while (n-- > 0)
	{
		if (*temp1 != *temp2)
			return (*temp1 - *temp2);
		temp1++;
		temp2++;
	}
	return (0);
}
