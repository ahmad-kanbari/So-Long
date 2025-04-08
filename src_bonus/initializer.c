/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akanbari <akanbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 17:21:21 by akanbari          #+#    #+#             */
/*   Updated: 2023/11/23 17:35:54 by akanbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

int	initialize_game(t_mygame *game)
{
	game->hero.hero = 0;
	game->item.item = 0;
	game->enemy.enemy_count = 0;
	game->enemy.i_counter = 0;
	game->enemy.height = SIZE_PXL;
	game->enemy.width = SIZE_PXL;
	game->exit = 0;
	game->score = 0;
	game->currentscore = 0;
	game->steps = 0;
	game->wall.height = SIZE_PXL;
	game->wall.width = SIZE_PXL;
	game->ground.height = SIZE_PXL;
	game->ground.width = SIZE_PXL;
	game->bunker.height = SIZE_PXL;
	game->bunker.width = SIZE_PXL;
	game->dfs.is_collectable = 0;
	game->dfs.is_exit = 0;
	game->dfs.tmp_x = 0;
	game->dfs.tmp_y = 0;
	game->hero.photo_counter = 0;
	game->enemy.direction[0] = 1;
	set_tmp_dfs_map(game);
	return (0);
}

int	generate_random_number(int min, int max)
{
	return (min + rand() % (max - min + 1));
}
