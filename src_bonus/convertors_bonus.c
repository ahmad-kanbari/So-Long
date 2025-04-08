/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convertors_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akanbari <akanbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 14:49:51 by akanbari          #+#    #+#             */
/*   Updated: 2023/11/23 17:32:29 by akanbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	*convert_xpm(t_mygame *game, char *path)
{
	t_sprite	sprite;
	int			w;
	int			h;

	w = SIZE_PXL;
	h = SIZE_PXL;
	sprite.img = mlx_xpm_file_to_image(game->vars.mlx, path, &w, &h);
	return (sprite.img);
}

static void	load_objects_tomlx2(t_mygame *game)
{
	game->hero.up[0].img = convert_xpm(game, HERO_UP0);
	game->hero.up[1].img = convert_xpm(game, HERO_UP1);
	game->hero.up[2].img = convert_xpm(game, HERO_UP2);
	game->hero.up[3].img = convert_xpm(game, HERO_UP3);
	game->hero.down[0].img = convert_xpm(game, HERO_DOWN0);
	game->hero.down[1].img = convert_xpm(game, HERO_DOWN1);
	game->hero.down[2].img = convert_xpm(game, HERO_DOWN2);
	game->hero.down[3].img = convert_xpm(game, HERO_DOWN3);
	game->hero.left[0].img = convert_xpm(game, HERO_LEFT0);
	game->hero.left[1].img = convert_xpm(game, HERO_LEFT1);
	game->hero.left[2].img = convert_xpm(game, HERO_LEFT2);
	game->hero.left[3].img = convert_xpm(game, HERO_LEFT3);
	game->hero.right[0].img = convert_xpm(game, HERO_RIGHT0);
	game->hero.right[1].img = convert_xpm(game, HERO_RIGHT1);
	game->hero.right[2].img = convert_xpm(game, HERO_RIGHT2);
	game->hero.right[3].img = convert_xpm(game, HERO_RIGHT3);
}

int	load_objects_tomlx(t_mygame *game)
{
	load_objects_tomlx2(game);
	game->wall.img = convert_xpm(game, BORDER);
	game->item.img = convert_xpm(game, ITEM);
	game->ground.img = convert_xpm(game, GROUND);
	game->bunker.img = convert_xpm(game, EXIT);
	game->enemy.enemies[0].img = convert_xpm(game, ENEMY1);
	game->enemy.enemies[1].img = convert_xpm(game, ENEMY2);
	game->enemy.enemies[2].img = convert_xpm(game, ENEMY3);
	game->finish.img = convert_xpm(game, FINISH);
	return (0);
}

int	unload_objects2(t_mygame *game)
{
	mlx_destroy_image(game->vars.mlx, game->hero.up[0].img);
	mlx_destroy_image(game->vars.mlx, game->hero.up[1].img);
	mlx_destroy_image(game->vars.mlx, game->hero.up[2].img);
	mlx_destroy_image(game->vars.mlx, game->hero.up[3].img);
	mlx_destroy_image(game->vars.mlx, game->hero.down[0].img);
	mlx_destroy_image(game->vars.mlx, game->hero.down[1].img);
	mlx_destroy_image(game->vars.mlx, game->hero.down[2].img);
	mlx_destroy_image(game->vars.mlx, game->hero.down[3].img);
	mlx_destroy_image(game->vars.mlx, game->finish.img);
	return (0);
}

int	unload_objects(t_mygame *game)
{
	unload_objects2(game);
	mlx_destroy_image(game->vars.mlx, game->hero.left[0].img);
	mlx_destroy_image(game->vars.mlx, game->hero.left[1].img);
	mlx_destroy_image(game->vars.mlx, game->hero.left[2].img);
	mlx_destroy_image(game->vars.mlx, game->hero.left[3].img);
	mlx_destroy_image(game->vars.mlx, game->hero.right[0].img);
	mlx_destroy_image(game->vars.mlx, game->hero.right[1].img);
	mlx_destroy_image(game->vars.mlx, game->hero.right[2].img);
	mlx_destroy_image(game->vars.mlx, game->hero.right[3].img);
	mlx_destroy_image(game->vars.mlx, game->ground.img);
	mlx_destroy_image(game->vars.mlx, game->wall.img);
	mlx_destroy_image(game->vars.mlx, game->item.img);
	mlx_destroy_image(game->vars.mlx, game->bunker.img);
	mlx_destroy_image(game->vars.mlx, game->enemy.enemies[0].img);
	mlx_destroy_image(game->vars.mlx, game->enemy.enemies[1].img);
	mlx_destroy_image(game->vars.mlx, game->enemy.enemies[2].img);
	return (0);
}
