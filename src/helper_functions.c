/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akanbari <akanbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 18:12:38 by akanbari          #+#    #+#             */
/*   Updated: 2023/11/18 13:47:38 by akanbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

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
	game->hero.path = HERO;
	game->ground.path = GROUND;
	game->wall.path = BORDER;
	game->bunker.path = EXIT;
	game->item.path = ITEM;
	set_heights(game);
	set_widths(game);
	return (0);
}

int	load_objects_tomlx(t_mygame *game)
{
	game->hero.img = mlx_xpm_file_to_image(game->vars.mlx, game->hero.path,
			&game->hero.width, &game->hero.height);
	game->wall.img = mlx_xpm_file_to_image(game->vars.mlx, game->wall.path,
			&game->wall.width, &game->wall.height);
	game->item.img = mlx_xpm_file_to_image(game->vars.mlx, game->item.path,
			&game->item.width, &game->item.height);
	game->ground.img = mlx_xpm_file_to_image(game->vars.mlx, game->ground.path,
			&game->ground.width, &game->ground.height);
	game->bunker.img = mlx_xpm_file_to_image(game->vars.mlx, game->bunker.path,
			&game->bunker.width, &game->bunker.height);
	return (0);
}

int	unload_objects(t_mygame *game)
{
	mlx_destroy_image(game->vars.mlx, game->hero.img);
	mlx_destroy_image(game->vars.mlx, game->ground.img);
	mlx_destroy_image(game->vars.mlx, game->wall.img);
	mlx_destroy_image(game->vars.mlx, game->item.img);
	mlx_destroy_image(game->vars.mlx, game->bunker.img);
	return (0);
}
