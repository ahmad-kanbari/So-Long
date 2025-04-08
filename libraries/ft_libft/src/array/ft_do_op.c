/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_do_op.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akanbari <akanbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 21:57:48 by akanbari          #+#    #+#             */
/*   Updated: 2023/11/18 14:15:31 by akanbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_do_op(char *num1, char *sign, char *num2)
{
	int	n1;
	int	n2;
	int	result;

	result = 0;
	n1 = atoi(num1);
	n2 = atoi(num2);
	if (sign[0] == '-')
		result = n1 - n2;
	else if (sign[0] == '+')
		result = n1 + n2;
	else if (sign[0] == '*')
		result = n1 * n2;
	else if (sign[0] == '/')
		result = n1 / n2;
	else if (sign[0] == '%')
		result = n1 % n2;
	else 
		printf("Enter A Valid Sign");
	return (result);
}
