/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akanbari <akanbari@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 20:59:13 by akanbari          #+#    #+#             */
/*   Updated: 2023/09/30 00:24:13 by akanbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	str_len;

	str_len = ft_strlen(s);
	while (s[str_len] != (char)c && str_len != 0)
	{
		str_len--;
	}
	if (s[str_len] == (unsigned char)c)
		return ((char *)s + str_len);
	return (0);
}
