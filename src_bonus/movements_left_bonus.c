/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_left_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akanbari <akanbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 16:24:33 by akanbari          #+#    #+#             */
/*   Updated: 2023/11/23 17:14:58 by akanbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

static	void	move_left_e(t_mygame *game)
{
	ft_putimage(game, game->ground.img, game->position_y, \
		game->position_x - 1);
	ft_putimage(game, game->bunker.img, game->position_y, \
		game->position_x - 1);
	game->map[game->position_y][game->position_x - 1] = 'P';
	ft_putimage(game, game->hero.left[game->hero.photo_counter].img, \
		game->position_y, game->position_x - 1);
	ft_putimage(game, game->ground.img, game->position_y, game->position_x);
	game->map[game->position_y][game->position_x] = '0';
	game->position_x -= 1;
	if (game->currentscore == game->item.item)
		finish_game_won(game);
}

static	void	move_left_x(t_mygame *game)
{
	game->map[game->position_y][game->position_x - 1] = 'P';
	ft_putimage(game, game->hero.left[game->hero.photo_counter].img, \
		game->position_y, game->position_x - 1);
	mlx_string_put(game->vars.mlx, game->vars.window, 250, 250, \
		0x000000FF, "GAME FINISHED");
	ft_putimage(game, game->finish.img, \
		game->position_y, game->position_x);
	usleep(100000);
	finish_game_lost(game);
}

int	move_left(t_mygame *game)
{
	if (game->map[game->position_y][game->position_x - 1] == '0')
		move_left_utill_0(game);
	else if (game->map[game->position_y][game->position_x - 1] == 'C')
	{
		ft_putimage(game, game->ground.img, game->position_y, \
			game->position_x - 1);
		game->map[game->position_y][game->position_x - 1] = 'P';
		ft_putimage(game, game->hero.left[game->hero.photo_counter].img, \
			game->position_y, game->position_x - 1);
		game->map[game->position_y][game->position_x] = '0';
		game->map[game->exit_y][game->exit_x] = 'E';
		ft_putimage(game, game->ground.img, game->exit_y, game->exit_x);
		ft_putimage(game, game->bunker.img, game->exit_y, game->exit_x);
		ft_putimage(game, game->ground.img, game->position_y, game->position_x);
		game->position_x -= 1;
		game->currentscore++;
		ft_printf("SCORE :  %d\n", game->currentscore);
	}
	else if (game->map[game->position_y][game->position_x - 1] == 'E')
		move_left_e(game);
	else if (game->map[game->position_y][game->position_x - 1] == 'X')
		move_left_x(game);
	return (0);
}
