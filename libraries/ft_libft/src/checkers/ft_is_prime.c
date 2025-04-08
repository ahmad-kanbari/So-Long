/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akanbari <akanbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 00:51:22 by akanbari          #+#    #+#             */
/*   Updated: 2023/11/16 22:03:02 by akanbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_is_prime(int nb)
{
	int	index;

	if (nb < 2)
		return (0);
	index = 2;
	while (index < nb)
	{
		if (nb % index == 0)
			return (0);
		index++;
	}
	return (1);
}
