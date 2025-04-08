/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akanbari <akanbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 00:52:50 by akanbari          #+#    #+#             */
/*   Updated: 2023/11/16 22:25:51 by akanbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	helper(long n, char *base, int len, int fd)
{
	if (n < 0)
		ft_putchar_fd('-', fd);
	n *= 1 - ((n < 0) * 2);
	if (n >= len)
		helper(n / len, base, len, fd);
	ft_putchar_fd(base[n % len], fd);
}

static int	check_reps(char *base, int index)
{
	int	i;

	i = index + 1;
	while (base[i] != '\0')
	{
		if (base[index] == base[i])
			return (1);
		i++;
	}
	return (0);
}

void	ft_putnbr_base(int nbr, char *base, int fd)
{
	int	len;

	len = 0;
	while (base[len] != '\0')
	{
		if (base[len] == '-' || base[len] == '+')
			return ;
		if (check_reps(base, len))
			return ;
		len++;
	}
	if (len > 1)
		helper((long) nbr, base, len, fd);
}
// n *= 1 - ((n < 0) * 2); is a compact way of conditionally inverting
// the sign of an integer 
//variable n based on whether it's negative or not.
