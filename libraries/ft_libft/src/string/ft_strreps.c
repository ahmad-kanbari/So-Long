/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strreps.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akanbari <akanbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 00:24:22 by akanbari          #+#    #+#             */
/*   Updated: 2023/11/18 14:09:08 by akanbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strreps(char	*line, char c)
{
	int	i;
	int	tabs;

	i = 0;
	tabs = 0;
	while (line[i])
		if (line[i++] == c)
			tabs++;
	return (tabs);
}
