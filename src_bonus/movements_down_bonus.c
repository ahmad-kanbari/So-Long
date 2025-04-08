/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_down_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akanbari <akanbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 16:19:43 by akanbari          #+#    #+#             */
/*   Updated: 2023/11/23 17:29:38 by akanbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

static	void	move_down_e(t_mygame *game)
{
	ft_putimage(game, game->ground.img, game->position_y + 1, \
		game->position_x);
	ft_putimage(game, game->bunker.img, game->position_y + 1, \
		game->position_x);
	game->map[game->position_y + 1][game->position_x] = 'P';
	ft_putimage(game, game->hero.up[game->hero.photo_counter].img, \
	game->position_y + 1, game->position_x);
	ft_putimage(game, game->ground.img, game->position_y, game->position_x);
	game->map[game->position_y][game->position_x] = '0';
	game->position_y += 1;
	if (game->currentscore == game->item.item)
		finish_game_won(game);
}

static void	move_down_x(t_mygame *game)
{
	game->map[game->position_y + 1][game->position_x] = 'P';
	ft_putimage(game, game->hero.down[game->hero.photo_counter].img, \
			game->position_y + 1, game->position_x);
	mlx_string_put(game->vars.mlx, game->vars.window, 250, 250, \
		0x000000FF, "GAME FINISHED");
	finish_game_lost(game);
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
		ft_putimage(game, game->hero.down[game->hero.photo_counter].img, \
			game->position_y + 1, game->position_x);
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
		move_down_e(game);
	else if (game->map[game->position_y + 1][game->position_x] == 'X')
		move_down_x(game);
	return (0);
}
