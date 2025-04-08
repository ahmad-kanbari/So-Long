/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akanbari <akanbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 21:26:56 by akanbari          #+#    #+#             */
/*   Updated: 2023/11/16 21:57:02 by akanbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//double array len calculator
int	ft_arrlen(char **a)
{
	int	i;

	i = 0;
	while (a && a[i])
		i++;
	return (i);
}
