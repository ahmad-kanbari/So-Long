/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akanbari <akanbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 20:07:24 by akanbari          #+#    #+#             */
/*   Updated: 2023/11/06 20:03:28 by akanbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_pfd(int n, int fd, int *plen)
{
	int	value;

	if (n < 0)
	{
		ft_putchar_pfd('-', fd, plen);
		n = -n;
	}
	if (n == -2147483648)
	{
		ft_putchar_pfd(50, fd, plen);
		n = 147483648;
	}
	if (n > 9)
	{
		ft_putnbr_pfd(n / 10, fd, plen);
	}
	value = n % 10 + '0';
	ft_putchar_pfd(value, fd, plen);
}
