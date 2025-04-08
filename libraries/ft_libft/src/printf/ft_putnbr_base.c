/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akanbari <akanbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 19:58:44 by akanbari          #+#    #+#             */
/*   Updated: 2023/07/24 21:04:09 by akanbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_doublechar(char *symbols);

void	ft_putnbr_base(t_uint nbr, char *base, int *plen)
{
	unsigned int		baseindex;

	baseindex = 0;
	while (base[baseindex])
	{
		if (base[baseindex] == '+' || base[baseindex] == '-')
			return ;
		++baseindex;
	}
	if (baseindex < 2)
		return ;
	if (ft_doublechar(base))
		return ;
	ft_printnbr_base(nbr, baseindex, base, plen);
}

int	ft_doublechar(char *symbols)
{
	int		i;
	int		j;

	i = 0;
	while (*(symbols + i))
	{
		j = i + 1;
		while (*(symbols + j))
		{
			if (*(symbols + i) == *(symbols + j))
				return (1);
			++j;
		}
		++i;
	}
	return (0);
}
