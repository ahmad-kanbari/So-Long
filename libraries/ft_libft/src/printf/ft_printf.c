/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akanbari <akanbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 20:05:43 by akanbari          #+#    #+#             */
/*   Updated: 2023/11/06 20:03:07 by akanbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_helper(char c, va_list *args, int *plen)
{
	if (c == '%')
		ft_putchar_pfd('%', 1, plen);
	else if (c == 's') 
		ft_putstr_pfd((char *)va_arg(*args, char *), 1, plen);
	else if (c == 'c')
		ft_putchar_pfd(((char)(va_arg(*args, int))), 1, plen);
	else if (c == 'i' || c == 'd')
		ft_putnbr_pfd((int)va_arg(*args, int), 1, plen);
	else if (c == 'u')
		ft_putnbr_unsigned_fd((t_uint)va_arg(*args, t_uint), 1, plen);
	else if (c == 'x')
		ft_print_hex_small((t_uint)va_arg(*args, t_uint), plen);
	else if (c == 'X')
		ft_print_hex_big((t_uint)va_arg(*args, t_uint), plen);
	else if (c == 'p')
		ft_print_address((t_ullint)va_arg(*args, t_ullint), plen);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		plen;

	plen = 0;
	va_start(args, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			ft_printf_helper(*format, &args, &plen);
		}
		else
			ft_putchar_pfd(*format, 1, &plen);
		format++;
	}
	va_end(args);
	return (plen);
}
// // //iam putting inside  helper function a pointer to a struct , 
// that's why i have to deference it.
// int main(void)
// {   
// 	int a = 525;
// 	int *b = NULL;
// 	//printf("The Original Printf:%c , %d , %s , %u, %% ,
//%x , %X , %u, %p , %p\n",'l',6,"hello",5, -24, 2342, 497,&a, b);
// 	//ft_printf("My Own Printf:%c , %d , %s , %u, %% , 
//%x , %X , %u, %p , %p\n",'l',6,"hello",5,-24, 2342, 497, &a, b);
// 	t_ullint i = printf("%x\n", -2294967295 );
// 	t_ullint j = ft_printf("%x\n", -2294967295 );
// 	printf("original : %llu , mine : %llu\n",i , j);
// 	//printf("%c", 'x');
// 	return (0);
// }
//for negative numbers in hex decimal the computer 
//turn the decimal numbers to binary ,
//it will fip the binaray and then it will add 1 to that binary, 
//then it will take each 4 bytes and  transform them into hexa decimal character
//if you cast your  negative number into  unsigned int it will convert it 
//automaticallly to the specific hex number.
//toos compliment 
//so for writing x and X we have to type casted into unsinged int, which will
//turn the decimal numbers to binary ,
//it will fip the binaray and then it will add 1 to that binary, 
//then it will take each 4 bytes and  transform them into hexa decimal character
//if you cast your  negative number into  unsigned int it will convert it 
//automaticallly to the specific hex number becuase of overflowing.
//But for writing p address , we have to type casted 
//into unsigned long long int,because when we take the address of the variable
//it has been already given to the function printf as an unsigned long long int
//that is why in %p we use unsinged long long int and recast it into hexa
//because adressess needs unsigned long long int numbers to get represented
//in the computer or  to be represented as hexadecimal.
//why we can not use long long int numbers in x ?
//because in the original printf the %x and %X can only take integer
//as maximum value, otherwise it will lead to output ffffff
//or undefined behavior, if i want to use unsigne int i have 
// to specify another flag called %lx which is out of our scope.
