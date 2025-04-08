/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_helpers_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akanbari <akanbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 20:40:30 by akanbari          #+#    #+#             */
/*   Updated: 2023/11/23 17:14:40 by akanbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	ft_putimage(t_mygame *game, void *img, int position_y, int position_x)
{
	mlx_put_image_to_window(game->vars.mlx, game->vars.window, \
		img, position_y * SIZE_PXL, position_x * SIZE_PXL);
}

void	move_up_utill_0(t_mygame *game)
{
	int	i;

	i = game->hero.photo_counter;
	game->map[game->position_y - 1][game->position_x] = 'P';
	ft_putimage(game, game->hero.up[i].img, game->position_y - 1, \
			game->position_x);
	game->map[game->position_y][game->position_x] = '0';
	ft_putimage(game, game->ground.img, game->position_y, game->position_x);
	game->map[game->exit_y][game->exit_x] = 'E';
	ft_putimage(game, game->bunker.img, game->exit_y, game->exit_x);
	game->position_y -= 1;
}

void	move_down_utill_0(t_mygame *game)
{
	int	i;

	i = game->hero.photo_counter;
	game->map[game->position_y + 1][game->position_x] = 'P';
	ft_putimage(game, game->hero.down[i].img, game->position_y + 1, \
			game->position_x);
	game->map[game->position_y][game->position_x] = '0';
	ft_putimage(game, game->ground.img, game->position_y, game->position_x);
	game->map[game->exit_y][game->exit_x] = 'E';
	ft_putimage(game, game->bunker.img, game->exit_y, game->exit_x);
	game->position_y += 1;
}

void	move_left_utill_0(t_mygame *game)
{
	int	i;

	i = game->hero.photo_counter;
	game->map[game->position_y][game->position_x - 1] = 'P';
	ft_putimage(game, game->hero.left[i].img, game->position_y, \
			game->position_x - 1);
	game->map[game->position_y][game->position_x] = '0';
	ft_putimage(game, game->ground.img, game->position_y, game->position_x);
	game->map[game->exit_y][game->exit_x] = 'E';
	ft_putimage(game, game->bunker.img, game->exit_y, game->exit_x);
	game->position_x -= 1;
}

void	move_right_utill_0(t_mygame *game)
{
	int	i;

	i = game->hero.photo_counter;
	game->map[game->position_y][game->position_x + 1] = 'P';
	ft_putimage(game, game->hero.right[i].img, game->position_y, \
			game->position_x + 1);
	game->map[game->position_y][game->position_x] = '0';
	ft_putimage(game, game->ground.img, game->position_y, game->position_x);
	game->map[game->exit_y][game->exit_x] = 'E';
	ft_putimage(game, game->bunker.img, game->exit_y, game->exit_x);
	game->position_x += 1;
}
