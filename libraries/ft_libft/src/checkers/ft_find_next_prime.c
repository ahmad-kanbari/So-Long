/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akanbari <akanbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 00:51:47 by akanbari          #+#    #+#             */
/*   Updated: 2023/11/18 14:34:04 by akanbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_sqrtt(int nb)
{
	unsigned int	i;

	if (nb < 0)
		return (0);
	if (nb < 2)
		return (1);
	i = 0;
	if (nb == 2147483647)
		return (1);
	while (1)
	{
		if (i * i >= (unsigned int)nb)
			return (i);
		i++;
	}
	return (i);
}

int	ft_is_prime(int nb)
{
	int	index;

	if (nb % 2 == 0)
		return (0);
	index = 3;
	while (index < ft_sqrtt(nb))
	{
		if (nb % index == 0)
			return (0);
		index = index + 2;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	if (nb <= 2)
		return (2);
	if (ft_is_prime(nb))
		return (nb);
	if (nb % 2 == 0)
		nb++;
	while (!ft_is_prime(nb))
		nb = nb + 2;
	return (nb);
}
