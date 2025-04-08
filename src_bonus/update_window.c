/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akanbari <akanbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 16:49:53 by akanbari          #+#    #+#             */
/*   Updated: 2023/11/23 17:37:41 by akanbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

// for dir1 1->right  ,2->left, 3->up, 4->down , for enemy is it for enemy id
void	moving_enemy(t_mygame *game, int dir1, int enemy)
{
	if (dir1 == 1)
		move_enemy_right(game, game->enemy.enemies[enemy].pos_y, \
			game->enemy.enemies[enemy].pos_x, enemy);
	else if (dir1 == 2)
		move_enemy_left(game, game->enemy.enemies[enemy].pos_y, \
			game->enemy.enemies[enemy].pos_x, enemy);
	else if (dir1 == 3)
		move_enemy_up(game, game->enemy.enemies[enemy].pos_y, \
			game->enemy.enemies[enemy].pos_x, enemy);
	else if (dir1 == 4)
		move_enemy_down(game, game->enemy.enemies[enemy].pos_y, \
			game->enemy.enemies[enemy].pos_x, enemy);
}

static	void	update_window_helper2(t_mygame *game)
{
	if (game->enemy.direction[0] == 1)
	{
		moving_enemy(game, 1, 0);
		moving_enemy(game, 2, 1);
	}
	else if (game->enemy.direction[0] == 2)
	{
		moving_enemy(game, 2, 0);
		moving_enemy(game, 3, 1);
	}
	else if (game->enemy.direction[0] == 3)
	{
		moving_enemy(game, 3, 0);
		moving_enemy(game, 4, 1);
	}
	else if (game->enemy.direction[0] == 4)
	{
		moving_enemy(game, 4, 0);
		moving_enemy(game, 1, 1);
	}
	usleep(SPEED);
}

static	void	update_window_helper3(t_mygame *game)
{
	if (game->enemy.direction[0] == 1)
	{
		moving_enemy(game, 1, 0);
		moving_enemy(game, 2, 1);
		moving_enemy(game, 3, 2);
	}
	else if (game->enemy.direction[0] == 2)
	{
		moving_enemy(game, 2, 0);
		moving_enemy(game, 3, 1);
		moving_enemy(game, 4, 2);
	}
	else if (game->enemy.direction[0] == 3)
	{
		moving_enemy(game, 3, 0);
		moving_enemy(game, 4, 1);
		moving_enemy(game, 1, 2);
	}
	else if (game->enemy.direction[0] == 4)
	{
		moving_enemy(game, 4, 0);
		moving_enemy(game, 1, 1);
		moving_enemy(game, 2, 2);
	}
	usleep(SPEED);
}

int	update_window(t_mygame *game)
{
	if (game->enemy.enemy_count == 1)
	{
		if (game->enemy.direction[0] == 1)
			move_enemy_right(game, game->enemy.enemies[0].pos_y, \
				game->enemy.enemies[0].pos_x, 0);
		else if (game->enemy.direction[0] == 2)
			move_enemy_left(game, game->enemy.enemies[0].pos_y, \
				game->enemy.enemies[0].pos_x, 0);
		else if (game->enemy.direction[0] == 3)
			move_enemy_up(game, game->enemy.enemies[0].pos_y, \
				game->enemy.enemies[0].pos_x, 0);
		else if (game->enemy.direction[0] == 4)
			move_enemy_down(game, game->enemy.enemies[0].pos_y, \
				game->enemy.enemies[0].pos_x, 0);
		usleep(SPEED);
	}
	else if (game->enemy.enemy_count == 2)
		update_window_helper2(game);
	else if (game->enemy.enemy_count == 3)
		update_window_helper3(game);
	else 
		return (ft_printf("The enemies must be between 1 and 3 on the map"), \
			finish_game(game), exit(1), 1);
	return (0);
}
