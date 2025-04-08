/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbr_base.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akanbari <akanbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 21:31:52 by akanbari          #+#    #+#             */
/*   Updated: 2023/11/06 20:03:09 by akanbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printnbr_base(t_uint num, int basevalue, char *symbols, int *plen)
{
	long	nlong;

	nlong = num;
	if (nlong >= basevalue)
		ft_printnbr_base(nlong / basevalue, basevalue, symbols, plen);
	ft_putchar_pfd(symbols[nlong % basevalue], 1, plen);
}
