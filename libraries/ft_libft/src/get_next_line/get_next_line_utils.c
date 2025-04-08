/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akanbari <akanbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 19:38:44 by akanbari          #+#    #+#             */
/*   Updated: 2023/11/06 19:45:02 by akanbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_gstrlen(char *str)
{
	int	len;

	len = 0;
	if (!str)
		return (0);
	while (str[len])
		len++;
	return (len);
}

char	*ft_strndup(const char *s, int n)
{
	char	*new_str;
	int		i;

	if (!s || n == 0)
		return (0);
	new_str = (char *)malloc((n + 1) * sizeof(char));
	if (!(new_str))
		return (0);
	i = -1;
	while (++i < n)
		new_str[i] = s[i];
	new_str[i] = 0;
	return (new_str);
}

char	*strnjoin(char **array, char **buf)
{
	char	*new_buf;
	int		len_array;
	int		len_buf;
	int		i;

	len_array = ft_gstrlen(*array);
	len_buf = ft_gstrlen(*buf);
	new_buf = (char *)malloc((len_array + len_buf + 1) * sizeof(char));
	if (!new_buf)
		return (0);
	i = -1;
	while (++i < len_array)
		new_buf[i] = (*array)[i];
	while (i < len_array + len_buf)
	{
		new_buf[i] = (*buf)[i - len_array];
		i++;
	}
	new_buf[i] = 0;
	free(*buf);
	free(*array);
	return (new_buf);
}
