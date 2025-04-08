/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akanbari <akanbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 15:20:57 by akanbari          #+#    #+#             */
/*   Updated: 2023/11/23 15:35:15 by akanbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static	void	move_left_helper(t_mygame *game)
{
	ft_putimage(game, game->ground.img, game->position_y, \
		game->position_x - 1);
	ft_putimage(game, game->bunker.img, game->position_y, \
		game->position_x - 1);
	game->map[game->position_y][game->position_x - 1] = 'P';
	ft_putimage(game, game->hero.img, game->position_y, game->position_x - 1);
	ft_putimage(game, game->ground.img, game->position_y, game->position_x);
	game->map[game->position_y][game->position_x] = '0';
	game->position_x -= 1;
	if (game->currentscore == game->item.item)
		finish_game(game);
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
		ft_putimage(game, game->hero.img, game->position_y, \
			game->position_x - 1);
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
		move_left_helper(game);
	return (0);
}

static	void	move_right_helper(t_mygame *game)
{
	ft_putimage(game, game->ground.img, game->position_y, \
		game->position_x + 1);
	ft_putimage(game, game->bunker.img, game->position_y, \
		game->position_x + 1);
	game->map[game->position_y][game->position_x + 1] = 'P';
	ft_putimage(game, game->hero.img, game->position_y, game->position_x + 1);
	ft_putimage(game, game->ground.img, game->position_y, game->position_x);
	game->map[game->position_y][game->position_x] = '0';
	game->position_x += 1;
	if (game->currentscore == game->item.item)
		finish_game(game);
}

int	move_right(t_mygame *game)
{
	if (game->map[game->position_y][game->position_x + 1] == '0')
		move_right_utill_0(game);
	else if (game->map[game->position_y][game->position_x + 1] == 'C')
	{
		ft_putimage(game, game->ground.img, game->position_y, \
			game->position_x + 1);
		game->map[game->position_y][game->position_x + 1] = 'P';
		ft_putimage(game, game->hero.img, game->position_y, \
			game->position_x + 1);
		ft_putimage(game, game->ground.img, game->position_y, game->position_x);
		game->map[game->position_y][game->position_x] = '0';
		game->map[game->exit_y][game->exit_x] = 'E';
		ft_putimage(game, game->ground.img, game->exit_y, game->exit_x);
		ft_putimage(game, game->bunker.img, game->exit_y, game->exit_x);
		ft_putimage(game, game->ground.img, game->position_y, game->position_x);
		game->position_x += 1;
		game->currentscore++;
		ft_printf("SCORE :  %d\n", game->currentscore);
	}
	else if (game->map[game->position_y][game->position_x + 1] == 'E')
		move_right_helper(game);
	return (0);
}
