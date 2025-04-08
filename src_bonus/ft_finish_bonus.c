/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_finish_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akanbari <akanbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 15:38:24 by akanbari          #+#    #+#             */
/*   Updated: 2023/11/23 16:09:30 by akanbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

int	finish_game_lost(t_mygame *game)
{
	unload_objects(game);
	mlx_destroy_window(game->vars.mlx, game->vars.window);
	free(game->vars.mlx);
	free(game->map);
	ft_printf("You Lost You have Been Killed, Try Again");
	exit(0);
	return (0);
}

int	finish_game_won(t_mygame *game)
{
	unload_objects(game);
	mlx_destroy_window(game->vars.mlx, game->vars.window);
	free(game->vars.mlx);
	free(game->map);
	ft_printf("Congratulation, You Won");
	exit(0);
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

void	check_paths2(t_mygame *game)
{
	if (game->ground.img == NULL)
		return (ft_printf("Wrong XPM File"), exit(1));
	if (game->wall.img == NULL)
		return (ft_printf("Wrong XPM File"), exit(1));
	if (game->bunker.img == NULL)
		return (ft_printf("Wrong XPM File"), exit(1));
	if (game->item.img == NULL)
		return (ft_printf("Wrong XPM File"), exit(1));
	if (game->enemy.enemies[0].img == NULL)
		return (ft_printf("Wrong XPM File"), exit(1));
	if (game->enemy.enemies[1].img == NULL)
		return (ft_printf("Wrong XPM File"), exit(1));
	if (game->enemy.enemies[2].img == NULL)
		return (ft_printf("Wrong XPM File"), exit(1));
	if (game->finish.img == NULL)
		return (ft_printf("Wrong XPM File"), exit(1));
}

void	check_paths(t_mygame *game)
{
	int	i;

	i = -1;
	while (++i < 4)
	{
		if (game->hero.up[i].img == NULL)
			return (ft_printf("Wrong XPM File"), exit(1));
		if (game->hero.down[i].img == NULL)
			return (ft_printf("Wrong XPM File"), exit(1));
		if (game->hero.left[i].img == NULL)
			return (ft_printf("Wrong XPM File"), exit(1));
		if (game->hero.right[i].img == NULL)
			return (ft_printf("Wrong XPM File"), exit(1));
	}
	check_paths2(game);
}
