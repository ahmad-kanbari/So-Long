/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akanbari <akanbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 19:06:04 by akanbari          #+#    #+#             */
/*   Updated: 2023/11/06 19:38:56 by akanbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int	value;

	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n = -n;
	}
	if (n == -2147483648)
	{
		ft_putchar_fd(50, fd);
		n = 147483648;
	}
	if (n > 9)
	{
		ft_putnbr_fd(n / 10, fd);
	}
	value = n % 10 + '0';
	ft_putchar_fd(value, fd);
}
