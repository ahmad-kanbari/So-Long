/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_helpers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akanbari <akanbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 20:40:30 by akanbari          #+#    #+#             */
/*   Updated: 2023/11/23 15:19:53 by akanbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	move_up_utill_0(t_mygame *game)
{
	game->map[game->position_y - 1][game->position_x] = 'P';
	mlx_put_image_to_window(game->vars.mlx, game->vars.window, \
game->hero.img, (game->position_y - 1) * SIZE_PXL, game->position_x * SIZE_PXL);
	mlx_put_image_to_window(game->vars.mlx, game->vars.window, \
game->ground.img, (game->position_y * SIZE_PXL), (game->position_x * SIZE_PXL));
	game->map[game->position_y][game->position_x] = '0';
	game->map[game->exit_y][game->exit_x] = 'E';
	ft_putimage(game, game->bunker.img, game->exit_y, game->exit_x);
	game->position_y -= 1;
}

void	move_down_utill_0(t_mygame *game)
{
	game->map[game->position_y + 1][game->position_x] = 'P';
	mlx_put_image_to_window(game->vars.mlx, game->vars.window, \
game->hero.img, (game->position_y + 1) * SIZE_PXL, game->position_x * SIZE_PXL);
	mlx_put_image_to_window(game->vars.mlx, game->vars.window, \
game->ground.img, (game->position_y * SIZE_PXL), (game->position_x * SIZE_PXL));
	game->map[game->position_y][game->position_x] = '0';
	game->map[game->exit_y][game->exit_x] = 'E';
	ft_putimage(game, game->bunker.img, game->exit_y, game->exit_x);
	game->position_y += 1;
}

void	move_left_utill_0(t_mygame *game)
{
	game->map[game->position_y][game->position_x - 1] = 'P';
	mlx_put_image_to_window(game->vars.mlx, game->vars.window, \
game->hero.img, game->position_y * SIZE_PXL, (game->position_x - 1) * SIZE_PXL);
	mlx_put_image_to_window(game->vars.mlx, game->vars.window, \
game->ground.img, (game->position_y * SIZE_PXL), (game->position_x * SIZE_PXL));
	game->map[game->position_y][game->position_x] = '0';
	game->map[game->exit_y][game->exit_x] = 'E';
	ft_putimage(game, game->bunker.img, game->exit_y, game->exit_x);
	game->position_x -= 1;
}

void	move_right_utill_0(t_mygame *game)
{
	game->map[game->position_y][game->position_x + 1] = 'P';
	mlx_put_image_to_window(game->vars.mlx, game->vars.window, \
game->hero.img, game->position_y * SIZE_PXL, (game->position_x + 1) * SIZE_PXL);
	mlx_put_image_to_window(game->vars.mlx, game->vars.window, \
game->ground.img, (game->position_y * SIZE_PXL), (game->position_x * SIZE_PXL));
	game->map[game->position_y][game->position_x] = '0';
	game->map[game->exit_y][game->exit_x] = 'E';
	ft_putimage(game, game->bunker.img, game->exit_y, game->exit_x);
	game->position_x += 1;
}
