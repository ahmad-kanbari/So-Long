/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex_big.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akanbari <akanbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 19:20:58 by akanbari          #+#    #+#             */
/*   Updated: 2023/07/24 21:57:21 by akanbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_hex_big(t_uint nbr, int *plen)
{
	int		base_value;
	char	*hex_symbols;

	hex_symbols = "0123456789ABCDEF";
	base_value = 16;
	ft_printnbr_base(nbr, base_value, hex_symbols, plen);
}
