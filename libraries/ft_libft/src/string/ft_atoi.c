/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akanbari <akanbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 21:37:33 by akanbari          #+#    #+#             */
/*   Updated: 2023/07/19 14:51:11 by akanbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi_helper(const char *str, t_llint result, int *reverse, int *i);

int	ft_atoi(const char *str)
{
	int		i;
	int		reverse;
	t_llint	result;

	result = 0;
	i = 0;
	reverse = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ' )
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			reverse *= -1;
		i++;
	}
	result = 0;
	result = ft_atoi_helper(str, result, &reverse, &i);
	return (result);
}

int	ft_atoi_helper(const char *str, t_llint result, int *reverse, int *i)
{
	int	num;

	num = 0;
	while (str[*i] >= '0' && str[*i] <= '9')
	{
		num = str[(*i)++] - '0';
		if (*reverse != -1 && result > ((LLONG_MAX - num) / 10))
			return (-1);
		if ((result * -1) < ((LLONG_MIN + num) / 10))
			return (0);
		result = result * 10 + num;
	}
	return ((result) * (*reverse));
}
