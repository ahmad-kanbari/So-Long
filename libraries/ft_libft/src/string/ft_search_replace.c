/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_search_replace.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akanbari <akanbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 22:30:23 by akanbari          #+#    #+#             */
/*   Updated: 2023/11/16 22:33:03 by akanbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	find_char(char *str, char c)
{
	while (*str)
	{
		if (*str == c)
			return (1);
		str++;
	}
	return (0);
}

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

void	ft_search_replace(char *str, char to_be_replaced, char new)
{
	int	i;

	i = 0;
	if (find_char(str, to_be_replaced))
	{
		while (str[i])
		{
			if (str[i] == to_be_replaced)
				str[i] = new;
			i++;
		}
		ft_putstr(str);
	}
	else
		ft_putstr(str);
}
