/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akanbari <akanbari@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 15:56:20 by akanbari          #+#    #+#             */
/*   Updated: 2023/09/29 22:15:55 by akanbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*ptr;
	int		len;

	len = ft_strlen(s1);
	ptr = (char *)malloc((ft_strlen(s1) + 1) * sizeof(char));
	if (ptr == NULL)
		return (0);
	ft_strlcpy(ptr, s1, len + 1);
	return (ptr);
}
