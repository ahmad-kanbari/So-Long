/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akanbari <akanbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:04:59 by akanbari          #+#    #+#             */
/*   Updated: 2023/11/23 18:43:37 by akanbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

static	void	key_hooks_helper(t_mygame *game)
{
	draw_map(game);
	game->steps++;
	printf("STEPS =  '%d'\n", game->steps);
}

void	key_moves(t_mygame *game, int id)
{
	if (id == 1)
	{
		move_up(game);
		game->movement_flag = 0;
	}
	else if (id == 2)
	{
		move_down(game);
		game->movement_flag = 1;
	}
	else if (id == 3)
	{
		move_left(game);
		game->movement_flag = 2;
	}
	else if (id == 4)
	{
		move_right(game);
		game->movement_flag = 3;
	}
}

int	key_hooks(int keycode, t_mygame *game)
{
	if (keycode == ESC)
		finish_game(game);
	if (keycode == W || keycode == UP)
		key_moves(game, 1);
	if (keycode == S || keycode == DOWN)
		key_moves(game, 2);
	if (keycode == A || keycode == LEFT)
		key_moves(game, 3);
	if (keycode == D || keycode == RIGHT)
		key_moves(game, 4);
	if (keycode == D || keycode == A || keycode == W || keycode == S || \
	keycode == UP || keycode == DOWN || keycode == LEFT || keycode == RIGHT)
		key_hooks_helper(game);
	return (0);
}

static void	general_initializer(t_mygame *game)
{
	check_ber(game);
	ft_savemap(game);
	game->vars.size_x = ft_strlen(game->map[0]) - 1;
	isrectangle(game);
	ft_check_surr_walls(game);
	initialize_game(game);
	checking_map(game);
	set_variables(game);
	game->vars.mlx = mlx_init();
	load_objects_tomlx(game);
	game->map_size.h = game->vars.size_y * SIZE_PXL;
	game->map_size.w = game->vars.size_x * SIZE_PXL;
	check_paths(game);
	game->vars.window = mlx_new_window(game->vars.mlx, game->map_size.w, \
			game->map_size.h, GAME_NAME);
}

int	main(int ac, char **av)
{
	t_mygame	game;

	if (ac != 2)
		return (ft_printf("Only 2 argumenst are allowed"), \
		exit(1), 0);
	game.maplink = av[1];
	general_initializer(&game);
	draw_map(&game);
	mlx_key_hook(game.vars.window, key_hooks, &game);
	mlx_hook(game.vars.window, 17, 0, finish_game_won, &game);
	mlx_hook(game.vars.window, 17, 0, finish_game_lost, &game);
	mlx_loop_hook(game.vars.mlx, update_window, &game);
	mlx_loop(game.vars.mlx);
}
