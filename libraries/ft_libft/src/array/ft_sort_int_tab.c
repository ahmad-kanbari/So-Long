/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akanbari <akanbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 01:18:28 by akanbari          #+#    #+#             */
/*   Updated: 2023/11/16 22:02:06 by akanbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	swap(int *a, int *b)
{
	int	helper;

	if (a && b)
	{
		helper = *a;
		*a = *b;
		*b = helper;
	}
}

static void	sort(int *tab, int size)
{
	int	i;

	i = 0;
	while (i < size - 1)
	{
		if (*(tab + i) > *(tab + i + 1))
			swap((tab + i), (tab + i + 1));
		i++;
	}
}

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;

	i = 0;
	while (1)
	{
		if (*(tab + i) > *(tab + i + 1))
		{
			sort(tab, size);
			i = 0;
			continue ;
		}
		i++;
		if (i == size)
			break ;
	}
}
