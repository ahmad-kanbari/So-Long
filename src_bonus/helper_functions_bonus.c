/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akanbari <akanbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 18:12:38 by akanbari          #+#    #+#             */
/*   Updated: 2023/11/23 17:30:32 by akanbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

int	set_heights(t_mygame *game)
{
	game->hero.height = SIZE_PXL;
	game->ground.height = SIZE_PXL;
	game->wall.height = SIZE_PXL;
	game->bunker.height = SIZE_PXL;
	game->item.height = SIZE_PXL;
	return (0);
}

int	set_widths(t_mygame *game)
{
	game->hero.width = SIZE_PXL;
	game->ground.width = SIZE_PXL;
	game->wall.width = SIZE_PXL;
	game->bunker.width = SIZE_PXL;
	game->item.width = SIZE_PXL;
	return (0);
}

int	set_variables(t_mygame *game)
{
	game->hero.up[0].path = HERO_UP0;
	game->hero.up[1].path = HERO_UP1;
	game->hero.up[2].path = HERO_UP2;
	game->hero.up[3].path = HERO_UP3;
	game->hero.down[0].path = HERO_DOWN0;
	game->hero.down[1].path = HERO_DOWN1;
	game->hero.down[2].path = HERO_DOWN2;
	game->hero.down[3].path = HERO_DOWN3;
	game->hero.left[0].path = HERO_LEFT0;
	game->hero.left[1].path = HERO_LEFT1;
	game->hero.left[2].path = HERO_LEFT2;
	game->hero.left[3].path = HERO_LEFT3;
	game->ground.path = GROUND;
	game->wall.path = BORDER;
	game->bunker.path = EXIT;
	game->item.path = ITEM;
	game->finish.path = FINISH;
	set_heights(game);
	set_widths(game);
	return (0);
}

int	set_variables2(t_mygame *game)
{
	game->hero.right[0].path = HERO_RIGHT0;
	game->hero.right[1].path = HERO_RIGHT1;
	game->hero.right[2].path = HERO_RIGHT2;
	game->hero.right[3].path = HERO_RIGHT3;
	game->enemy.enemies[0].path = ENEMY1;
	game->enemy.enemies[1].path = ENEMY2;
	game->enemy.enemies[2].path = ENEMY3;
	return (0);
}
