/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers2_utilities.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akanbari <akanbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 21:12:01 by akanbari          #+#    #+#             */
/*   Updated: 2023/11/23 15:17:10 by akanbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	check_invalid_chars(t_mygame *game, int pos_x, int pos_y)
{
	char	*valid_chars;

	valid_chars = "PEC10\n";
	if (ft_strchr(valid_chars, game->map[pos_y][pos_x]) == NULL)
		return (ft_printf("Map has no access and wrong blocks\n"),
			free(game->map), exit(0), 0);
	else
		return (0);
}

static void	check_map_content_helper(t_mygame *game, int *i, int *j)
{
	while (game->map[*j][++(*i)])
	{
		check_invalid_chars(game, *i, *j);
		if (game->map[*j][*i] == 'P')
		{
			game->position_x = *i;
			game->position_y = *j;
			game->dfs.tmp_x = *i;
			game->dfs.tmp_y = *j;
			game->hero.hero++;
		}
		if (game->map[*j][*i] == 'E')
		{
			game->exit++;
			game->exit_x = *i;
			game->exit_y = *j;
		}
		if (game->map[*j][*i] == 'C')
			game->item.item++;
	}
}

int	check_map_content(t_mygame *game)
{
	int	i;
	int	j;

	j = -1;
	while (game->map[++j])
	{
		i = -1;
		check_map_content_helper(game, &i, &j);
	}
	return (1);
}

int	checking_map(t_mygame *game)
{
	check_map_content(game);
	if (game->hero.hero == 0)
		return (ft_printf("Error : Didn't find player"),
			free(game->map), exit(1), 0);
	if (game->hero.hero > 1)
		return (ft_printf("Error : Player more than 1"),
			free(game->map), exit(1), 0);
	if (game->item.item == 0)
		return (ft_printf("Error : Didn't find item(C)"),
			free(game->map), exit(1), 0);
	if (game->exit == 0)
		return (ft_printf("Error : Didn't find exit(E)"),
			free(game->map), exit(1), 0);
	if (game->exit > 1)
		return (ft_printf("Error : There are more than 1 exit(E)"),
			free(game->map), exit(1), 0);
	ft_dfs(game, game->dfs.tmp_x, game->dfs.tmp_y);
	if (game->dfs.is_collectable != game->item.item || game->dfs.is_exit != 1)
		return (printf("\n\nInvalid Map Path, Exit or Coins not met\n\n"),
			free(game->map), exit(1), 0);
	return (0);
}

int	finish_game(t_mygame *game)
{
	unload_objects(game);
	mlx_destroy_window(game->vars.mlx, game->vars.window);
	free(game->vars.mlx);
	free(game->map);
	exit(0);
	return (0);
}
