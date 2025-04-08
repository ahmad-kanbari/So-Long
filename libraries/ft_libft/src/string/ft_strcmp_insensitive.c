/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp_insensitive.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akanbari <akanbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 21:53:35 by akanbari          #+#    #+#             */
/*   Updated: 2023/11/16 22:39:07 by akanbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp_insensitive(const char *s1, const char *s2)
{
	char	c1;
	char	c2;

	while (*s1 && *s2)
	{
		while (*s1 && !ft_isalnum(*s1))
			s1++;
		c1 = ft_tolower(*s1);
		while (*s2 && !ft_isalnum(*s2))
			s2++;
		c2 = ft_tolower(*s2);
		if (c1 != c2)
			return ((unsigned char)c1 - (unsigned char)c2);
		if (!c1 || !c2)
			break ;
		s1++;
		s2++;
	}
	return (0);
}
