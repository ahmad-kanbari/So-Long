/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akanbari <akanbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 02:24:52 by akanbari          #+#    #+#             */
/*   Updated: 2023/11/16 22:38:04 by akanbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	counter(char const *s, char c)
{
	size_t	i;
	int		counter;

	i = 0;
	counter = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && ((s[i + 1] == c) || (s[i + 1] == '\0')))
			counter++;
		i++;
	}
	return (counter);
}

char	**ft_split2(char const *s, char c)
{
	char		**str;
	size_t		i;
	const char	*ptr;

	i = 0;
	if (!s)
		return (NULL);
	str = (char **)malloc(sizeof(char *) * (counter(s, c) + 1));
	if (!str)
		return (NULL);
	while (*s)
	{
		if (*s != c)
		{
			ptr = s;
			while (*s && *s != c)
				s++;
			str[i] = ft_strdup_n(ptr, s - ptr);
			i++;
		}
		else
			s++;
	}
	str[i] = NULL;
	return (str);
}
