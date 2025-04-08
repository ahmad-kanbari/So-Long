/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akanbari <akanbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 16:35:00 by akanbari          #+#    #+#             */
/*   Updated: 2023/11/23 17:35:20 by akanbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

static int	draw_map2_helper(t_mygame *game, int i, int j)
{
	if (game->map[i][j] == '1')
	{
		mlx_put_image_to_window(game->vars.mlx, game->vars.window, \
		game->ground.img, (j * SIZE_PXL), (i * SIZE_PXL));
		mlx_put_image_to_window(game->vars.mlx, game->vars.window, \
		game->wall.img, (j * SIZE_PXL), (i * SIZE_PXL));
	}
	else if (game->map[i][j] == '0')
		mlx_put_image_to_window(game->vars.mlx, game->vars.window, \
		game->ground.img, (j * SIZE_PXL), (i * SIZE_PXL));
	else if (game->map[i][j] == 'X')
	{
		mlx_put_image_to_window(game->vars.mlx, game->vars.window, \
		game->ground.img, (j * SIZE_PXL), (i * SIZE_PXL));
		mlx_put_image_to_window(game->vars.mlx, game->vars.window, \
		game->enemy.enemies[0].img, (j * SIZE_PXL), (i * SIZE_PXL));
	}
	return (1);
}

static void	draw_map3_helper2(t_mygame *game, int i, int j, int *n)
{
	if (game->movement_flag == 0)
	{
		mlx_put_image_to_window(game->vars.mlx, game->vars.window, \
			game->ground.img, (j * SIZE_PXL), (i * SIZE_PXL));
		mlx_put_image_to_window(game->vars.mlx, game->vars.window, \
			game->hero.up[*n].img, (j * SIZE_PXL), (i * SIZE_PXL));
		game->hero.photo_counter++;
	}
	else if (game->movement_flag == 1)
	{
		mlx_put_image_to_window(game->vars.mlx, game->vars.window, \
			game->ground.img, (j * SIZE_PXL), (i * SIZE_PXL));
		mlx_put_image_to_window(game->vars.mlx, game->vars.window, \
			game->hero.down[*n].img, (j * SIZE_PXL), (i * SIZE_PXL)); 
		game->hero.photo_counter++;
	}
}

static	void	draw_map3_helper(t_mygame *game, int i, int j, int *n)
{
	if (game->movement_flag == 0)
		draw_map3_helper2(game, i, j, n);
	else if (game->movement_flag == 1)
		draw_map3_helper2(game, i, j, n);
	else if (game->movement_flag == 2)
	{
		mlx_put_image_to_window(game->vars.mlx, game->vars.window, \
			game->ground.img, (j * SIZE_PXL), (i * SIZE_PXL));
		mlx_put_image_to_window(game->vars.mlx, game->vars.window, \
			game->hero.left[*n].img, (j * SIZE_PXL), (i * SIZE_PXL));
		game->hero.photo_counter++;
	}
	else if (game->movement_flag == 3)
	{
		mlx_put_image_to_window(game->vars.mlx, game->vars.window, \
			game->ground.img, (j * SIZE_PXL), (i * SIZE_PXL));
		mlx_put_image_to_window(game->vars.mlx, game->vars.window, \
			game->hero.right[*n].img, (j * SIZE_PXL), (i * SIZE_PXL));
		game->hero.photo_counter++;
	}
}

static void	draw_map2(t_mygame *game, int i, int j)
{
	int	n;

	if (game->hero.photo_counter == 4)
		game->hero.photo_counter = 0;
	n = game->hero.photo_counter;
	draw_map2_helper(game, i, j);
	if (game->map[i][j] == 'P' )
		draw_map3_helper(game, i, j, &n);
	else if (game->map[i][j] == 'E')
	{
		mlx_put_image_to_window(game->vars.mlx, game->vars.window, \
			game->ground.img, (j * SIZE_PXL), (i * SIZE_PXL));
		mlx_put_image_to_window(game->vars.mlx, game->vars.window, \
			game->bunker.img, (j * SIZE_PXL), (i * SIZE_PXL));
	}
	else if (game->map[i][j] == 'C')
	{
		mlx_put_image_to_window(game->vars.mlx, game->vars.window, \
			game->ground.img, (j * SIZE_PXL), (i * SIZE_PXL));
		mlx_put_image_to_window(game->vars.mlx, game->vars.window, \
			game->item.img, (j * SIZE_PXL), (i * SIZE_PXL));
	}
}

int	draw_map(t_mygame *game)
{
	int	i;
	int	j;

	i = -1;
	while (game->map[++i])
	{
		j = -1;
		while (game->map[i][++j])
		{
			draw_map2(game, i, j);
			mlx_string_put(game->vars.mlx, game->vars.window, 40, 50, \
			0x000000FF, "Moves");
			mlx_string_put(game->vars.mlx, game->vars.window, 40, 70, \
			0x000000FF, ft_itoa(game->steps));
			mlx_string_put(game->vars.mlx, game->vars.window, 90, 50, \
			0x000000FF, "Current Score");
			mlx_string_put(game->vars.mlx, game->vars.window, 90, 70, \
			0x000000FF, ft_itoa(game->currentscore));
		}
	}
	return (0);
}
