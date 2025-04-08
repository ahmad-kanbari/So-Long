/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers_utilities.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akanbari <akanbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:14:35 by akanbari          #+#    #+#             */
/*   Updated: 2023/11/19 18:25:32 by akanbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	check_ber(t_mygame *game)
{
	char	*mapname;
	int		i;
	int		j;

	mapname = game->maplink;
	j = 0;
	i = ft_strlen(mapname) - 4;
	if (i < 0)
		return (ft_printf("Incorrect file type\n"), exit(1), 0);
	if (ft_strcmp(".ber", mapname + i) || !mapname)
		return (ft_printf("Incorrect file name\n"), exit(1), 0);
	return (0);
}

int	isrectangle(t_mygame *game)
{
	int	len1;
	int	len2;
	int	i;

	i = 0;
	while (game->map[i] && i < game->vars.size_y - 1)
	{
		len1 = ft_strlen_c(game->map[i], '\n');
		len2 = ft_strlen_c(game->map[i + 1], '\n');
		if (len1 != len2)
			return (ft_printf("Map is not rectangle\n"), exit(0), \
											free(game->map), 0);
		i++;
	}
	if (game->vars.size_x < 5 || game->vars.size_y < 3)
		return (ft_printf("Map is not complete and not valid\n"), exit(0), \
											free(game->map), 0);
	return (1);
}

static int	wallcheck(int point, t_mygame *game)
{
	if (point != '1')
	{
		ft_printf("Incomplete or incorrect map\n");
		free(game->map);
		return (1);
	}
	return (0);
}

int	ft_check_surr_walls(t_mygame *game)
{
	int	i;

	i = 0;
	while (game->map[i])
		if (wallcheck(game->map[i++][0], game))
			exit(1);
	i = 0;
	while (game->map[i])
		if (wallcheck(game->map[i++][game->vars.size_x - 1], game))
			exit(1);
	i = 0;
	while (game->map[game->vars.size_y - 1][i])
		if (wallcheck(game->map[game->vars.size_y - 1][i++], game))
			exit(1);
	i = 0;
	while (game->map[0][i] != '\n')
		if (wallcheck(game->map[0][i++], game))
			exit(1);
	return (0);
}
