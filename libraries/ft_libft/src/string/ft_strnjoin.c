/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akanbari <akanbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 22:16:25 by akanbari          #+#    #+#             */
/*   Updated: 2023/11/16 22:43:19 by akanbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*strnjoin(char **s1, char **s2)
{
	char	*new_buf;
	int		len_s1;
	int		len_s2;
	int		i;

	len_s1 = ft_strlen(*s1);
	len_s2 = ft_strlen(*s2);
	new_buf = (char *)malloc((len_s1 + len_s2 + 1) * sizeof(char));
	if (!new_buf)
		return (0);
	i = -1;
	while (++i < len_s1)
		new_buf[i] = (*s1)[i];
	while (i < len_s1 + len_s2)
	{
		new_buf[i] = (*s2)[i - len_s1];
		i++;
	}
	new_buf[i] = 0;
	free(*s2);
	free(*s1);
	return (new_buf);
}
