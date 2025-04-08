/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_delim.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akanbari <akanbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 00:46:27 by akanbari          #+#    #+#             */
/*   Updated: 2023/11/16 22:41:37 by akanbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	calc_len(int size, char **strs, char *sep)
{
	int	index;
	int	count;

	index = 0;
	count = 0;
	while (index < size)
		count += (ft_strlen(strs[index++]));
	count += (ft_strlen(sep) * (index));
	return (count);
}

char	*ft_strjoin_delim(int size, char **strs, char *sep)
{
	char	*array;
	char	*helper;
	int		index;

	if (size == 0)
		return ((char *)malloc(sizeof(char)));
	array = (char *)malloc(sizeof(char) * calc_len(size, strs, sep));
	if (array == NULL)
		return (0);
	index = 0;
	helper = array;
	while (index < size)
	{
		helper += ft_strlen(ft_strcpy(helper, strs[index]));
		if (index < size - 1)
			helper += ft_strlen(ft_strcpy(helper, sep));
		index++;
	}
	*helper = '\0';
	return (array);
}
