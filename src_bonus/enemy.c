/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akanbari <akanbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 13:08:19 by akanbari          #+#    #+#             */
/*   Updated: 2023/11/23 17:14:26 by akanbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

int	move_enemy_right(t_mygame *game, int j, int i, int enemy_id)
{
	if ((game->map[j][i] == 'X' && game->map[j][i + 1] == '0') \
		|| game->map[j][i + 1] == 'P')
	{
		if (game->map[j][i + 1] == 'P')
			finish_game_lost(game);
		game->map[j][i] = '0';
		ft_putimage(game, game->ground.img, i, j);
		game->map[j][i + 1] = 'X';
		ft_putimage(game, game->enemy.enemies[enemy_id].img, i + 1, j);
		game->enemy.enemies[enemy_id].pos_x++;
	}
	else 
		game->enemy.direction[enemy_id] = generate_random_number(1, 4);
	return (0);
}

int	move_enemy_left(t_mygame *game, int j, int i, int enemy_id)
{
	if ((game->map[j][i] == 'X' && game->map[j][i - 1] == '0' ) \
		|| game->map[j][i - 1] == 'P')
	{
		if (game->map[j][i - 1] == 'P')
			finish_game_lost(game);
		game->map[j][i] = '0';
		ft_putimage(game, game->ground.img, i, j);
		game->map[j][i - 1] = 'X';
		ft_putimage(game, game->enemy.enemies[enemy_id].img, i - 1, j);
		game->enemy.enemies[enemy_id].pos_x--;
	}
	else
		game->enemy.direction[enemy_id] = generate_random_number(1, 4);
	return (0);
}

int	move_enemy_up(t_mygame *game, int j, int i, int enemy_id)
{
	if ((game->map[j][i] == 'X' && game->map[j - 1][i] == '0') \
		|| game->map[j - 1][i] == 'P')
	{
		if (game->map[j - 1][i] == 'P')
			finish_game_lost(game);
		game->map[j][i] = '0';
		ft_putimage(game, game->ground.img, i, j);
		game->map[j - 1][i] = 'X';
		ft_putimage(game, game->enemy.enemies[enemy_id].img, i, j - 1);
		game->enemy.enemies[enemy_id].pos_y--;
	}
	else 
		game->enemy.direction[enemy_id] = generate_random_number(1, 4);
	return (0);
}

int	move_enemy_down(t_mygame *game, int j, int i, int enemy_id)
{
	if ((game->map[j][i] == 'X' && game->map[j + 1][i] == '0') || \
		game->map[j + 1][i] == 'P')
	{
		if (game->map[j + 1][i] == 'P')
			finish_game_lost(game);
		game->map[j][i] = '0';
		ft_putimage(game, game->ground.img, i, j);
		game->map[j + 1][i] = 'X';
		ft_putimage(game, game->enemy.enemies[enemy_id].img, i, j + 1);
		game->enemy.enemies[enemy_id].pos_y++;
	}
	else 
		game->enemy.direction[enemy_id] = generate_random_number(1, 4);
	return (0);
}
