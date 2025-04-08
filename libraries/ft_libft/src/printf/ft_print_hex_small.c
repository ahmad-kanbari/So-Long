/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex_small.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akanbari <akanbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 20:17:41 by akanbari          #+#    #+#             */
/*   Updated: 2023/07/24 21:56:37 by akanbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_hex_small(t_uint nbr, int *plen)
{
	int		base_value;
	char	*hex_symbols;

	hex_symbols = "0123456789abcdef";
	base_value = 16;
	ft_printnbr_base(nbr, base_value, hex_symbols, plen);
}
