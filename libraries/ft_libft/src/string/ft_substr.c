/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akanbari <akanbari@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 16:35:15 by akanbari          #+#    #+#             */
/*   Updated: 2023/09/30 00:25:42 by akanbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*ptr;

	i = 0;
	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
	{
		ptr = (char *)malloc(1);
		if (ptr == NULL)
			return (NULL);
		ptr[0] = '\0';
		return (ptr);
	}
	if (len > ft_strlen(s))
		len = ft_strlen(s);
	ptr = (char *)malloc((len * sizeof(char)) + 1);
	if (ptr == NULL)
		return (NULL);
	while (s[start] != '\0' && i < len)
		ptr[i++] = s[start++];
	ptr[i] = '\0';
	return (ptr);
}
