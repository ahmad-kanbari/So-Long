/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akanbari <akanbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 19:34:15 by akanbari          #+#    #+#             */
/*   Updated: 2023/11/06 20:02:32 by akanbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <ctype.h>
# include <stdlib.h>
# include <limits.h>
# include <stdarg.h>

typedef unsigned long long int	t_ullint;
typedef unsigned int			t_uint;

void	ft_putnbr_pfd(int n, int fd, int *plen);
void	ft_putnbr_unsigned_fd(t_uint n, int fd, int *plen);
int		ft_pstrlen(char *str);
void	ft_print_hex_small(t_uint nbr, int *plen);
void	ft_print_hex_big(t_uint nbr, int *plen);
int		ft_printf(const char *format, ...);
void	ft_putchar_pfd(char c, int fd, int *plen);
void	ft_putstr_pfd(char *s, int fd, int *plen);
void	ft_printnbr_base(t_uint num, int basevalue, char *symbols, int *plen);
void	ft_print_hexaddress(t_ullint nbr, int *plen);
void	ft_print_address(t_ullint nbr, int *plen);

#endif
