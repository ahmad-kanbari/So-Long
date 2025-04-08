/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akanbari <akanbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 20:05:56 by akanbari          #+#    #+#             */
/*   Updated: 2023/11/06 19:42:36 by akanbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr_pfd(char *s, int fd, int *plen)
{
	int	i;

	i = 0;
	if (s == NULL)
	{
		write(1, "(null)", 6);
		*plen += 6;
	}
	if (!s)
		return ;
	while (s[i] != '\0')
	{
		ft_putchar_pfd(s[i], fd, plen);
		i++;
	}
}
//original printf will add 5 to the returned len.
