/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akanbari <akanbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 20:38:09 by akanbari          #+#    #+#             */
/*   Updated: 2023/11/23 15:33:00 by akanbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_putimage(t_mygame *game, void *img, int position_y, int position_x)
{
	mlx_put_image_to_window(game->vars.mlx, game->vars.window, \
		img, position_y * SIZE_PXL, position_x * SIZE_PXL);
}

static void	move_up_helper(t_mygame *game)
{
	ft_putimage(game, game->ground.img, game->position_y - 1, \
			game->position_x);
	ft_putimage(game, game->bunker.img, game->position_y - 1, \
			game->position_x);
	game->map[game->position_y - 1][game->position_x] = 'P';
	ft_putimage(game, game->hero.img, game->position_y - 1, game->position_x);
	ft_putimage(game, game->ground.img, game->position_y, game->position_x);
	game->map[game->position_y][game->position_x] = '0';
	game->position_y -= 1;
	if (game->currentscore == game->item.item)
		finish_game(game);
}

int	move_up(t_mygame *game)
{
	if (game->map[game->position_y - 1][game->position_x] == '0')
		move_up_utill_0(game);
	else if (game->map[game->position_y - 1][game->position_x] == 'C')
	{
		game->map[game->position_y - 1][game->position_x] = 'P';
		ft_putimage(game, game->ground.img, \
			game->position_y - 1, game->position_x);
		ft_putimage(game, game->hero.img, \
			game->position_y - 1, game->position_x);
		game->map[game->position_y][game->position_x] = '0';
		game->map[game->exit_y][game->exit_x] = 'E';
		ft_putimage(game, game->ground.img, game->exit_y, game->exit_x);
		ft_putimage(game, game->bunker.img, game->exit_y, game->exit_x);
		game->position_y -= 1;
		game->currentscore++;
		ft_printf("SCORE :  %d\n", game->currentscore);
	}
	else if (game->map[game->position_y - 1][game->position_x] == 'E')
		move_up_helper(game);
	return (0);
}

static	void	move_down_helper(t_mygame *game)
{
	ft_putimage(game, game->ground.img, game->position_y + 1, game->position_x);
	ft_putimage(game, game->bunker.img, game->position_y + 1, game->position_x);
	game->map[game->position_y + 1][game->position_x] = 'P';
	ft_putimage(game, game->hero.img, game->position_y + 1, game->position_x);
	ft_putimage(game, game->ground.img, game->position_y, game->position_x);
	game->map[game->position_y][game->position_x] = '0';
	game->position_y += 1;
	if (game->currentscore == game->item.item)
		finish_game(game);
}

int	move_down(t_mygame *game)
{
	if (game->map[game->position_y + 1][game->position_x] == '0')
		move_down_utill_0(game);
	else if (game->map[game->position_y + 1][game->position_x] == 'C')
	{
		game->map[game->position_y + 1][game->position_x] = 'P';
		ft_putimage(game, game->ground.img, game->position_y + 1, \
			game->position_x);
		ft_putimage(game, game->hero.img, game->position_y + 1, \
			game->position_x);
		game->map[game->position_y][game->position_x] = '0';
		game->map[game->exit_y][game->exit_x] = 'E';
		ft_putimage(game, game->ground.img, game->exit_y, game->exit_x);
		ft_putimage(game, game->bunker.img, game->exit_y, game->exit_x);
		ft_putimage(game, game->ground.img, game->position_y, game->position_x);
		game->position_y += 1;
		game->currentscore++;
		ft_printf("SCORE :  %d\n", game->currentscore);
	}
	else if (game->map[game->position_y + 1][game->position_x] == 'E')
		move_down_helper(game);
	return (0);
}
