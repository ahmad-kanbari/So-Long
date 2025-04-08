/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_address.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akanbari <akanbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 20:04:24 by akanbari          #+#    #+#             */
/*   Updated: 2023/11/18 14:13:17 by akanbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_hexaddress(t_ullint nbr, int *plen);

void	ft_print_address(t_ullint nbr, int *plen)
{
	if ((void *) nbr == NULL)
	{
		ft_putstr_pfd("0x0", 1, plen);
		return ;
	}
	else
	{
		ft_putstr_pfd("0x", 1, plen);
		ft_print_hexaddress(nbr, plen);
	}
}

void	ft_print_hexaddress(t_ullint nbr, int *plen)
{
	char	*hex_symbols;

	hex_symbols = "0123456789abcdef";
	if (nbr >= 16)
	{
		ft_print_hexaddress(nbr / 16, plen);
	}
	ft_putchar_pfd(hex_symbols[nbr % 16], 1, plen);
}
//the address is in printf has been taken as unsigned int long long and 
//transformed into hex and printed out.