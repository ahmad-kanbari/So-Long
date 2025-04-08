/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akanbari <akanbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 20:36:54 by akanbari          #+#    #+#             */
/*   Updated: 2023/11/16 22:27:30 by akanbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len_numbers(int n)
{
	int	num_len;

	num_len = 0;
	if (n < 0)
	{
		num_len++;
		n *= -1;
	}
	while (n > 0)
	{
		n /= 10;
		num_len++;
	}
	return (num_len);
}

static char	*itoa_helper(char *num_ptr, int len, int num)
{
	if (num_ptr == NULL)
		return (NULL);
	num_ptr[len] = '\0';
	if (num < 0)
	{
		num_ptr[0] = '-';
		num *= -1;
		while (num != 0)
		{
			num_ptr[len - 1] = (num % 10) + 48;
			num = num / 10;
			len--;
		}
	}
	else
	{
		while (num != 0)
		{
			num_ptr[len - 1] = (num % 10) + 48;
			num = num / 10;
			len--;
		}
	}
	return (num_ptr);
}

char	*ft_itoa(int n)
{
	size_t	len;
	int		num;
	char	*num_ptr;

	num = n;
	if (num == 0)
		return (ft_strdup("0"));
	else if (n == (-2147483648))
		return (ft_strdup("-2147483648"));
	else
	{
		len = ft_len_numbers(num);
		num_ptr = (char *)malloc(sizeof(char) * (len + 1));
		num_ptr = itoa_helper(num_ptr, len, num);
		return (num_ptr);
	}
}
