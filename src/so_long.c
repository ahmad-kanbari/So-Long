/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akanbari <akanbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:04:59 by akanbari          #+#    #+#             */
/*   Updated: 2023/11/22 23:00:27 by akanbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	key_hooks(int keycode, t_mygame *game)
{
	if (keycode == ESC)
		finish_game(game);
	if (keycode == W || keycode == UP)
		move_up(game);
	if (keycode == S || keycode == DOWN)
		move_down(game);
	if (keycode == A || keycode == LEFT)
		move_left(game);
	if (keycode == D || keycode == RIGHT)
		move_right(game);
	if (keycode == D || keycode == A || keycode == W || keycode == S || \
	keycode == UP || keycode == DOWN || keycode == LEFT || keycode == RIGHT)
	{
		draw_map(game);
		game->steps++;
		printf("STEPS =  '%d'\n", game->steps);
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_mygame	game;

	if (ac != 2)
		return (ft_printf("Only 2 argumenst are allowed"), \
		exit(1), 0);
	game.maplink = av[1];
	check_ber(&game);
	ft_savemap(&game);
	game.vars.size_x = ft_strlen(game.map[0]) - 1;
	isrectangle(&game);
	ft_check_surr_walls(&game);
	initialize_game(&game);
	checking_map(&game);
	set_variables(&game);
	game.vars.mlx = mlx_init();
	load_objects_tomlx(&game);
	game.map_size.h = game.vars.size_y * SIZE_PXL;
	game.map_size.w = game.vars.size_x * SIZE_PXL;
	check_paths(&game);
	game.vars.window = mlx_new_window(game.vars.mlx, game.map_size.w,
			game.map_size.h, GAME_NAME);
	draw_map(&game);
	mlx_key_hook(game.vars.window, key_hooks, &game);
	mlx_hook(game.vars.window, 17, 0, finish_game, &game);
	mlx_loop(game.vars.mlx);
}

int	set_tmp_dfs_map(t_mygame *game)
{
	int		i;
	char	**str;

	i = -1;
	str = (char **)malloc(sizeof(char *) * (game->vars.size_y + 1));
	if (!str)
		return (ft_printf("error in mallocing\n"), exit(1), 1);
	game->dfs.tmp_map = str;
	while (++i < game->vars.size_y)
	{
		str[i] = (char *)malloc((game->vars.size_x) * sizeof(char) + 1);
		if (!(str[i]))
			return (exit(1), 0);
		str[i][game->vars.size_x] = 0;
		ft_memset(str[i], '0', game->vars.size_x);
	}
	return (1);
}

int	initialize_game(t_mygame *game)
{
	game->hero.hero = 0;
	game->item.item = 0;
	game->exit = 0;
	game->score = 0;
	game->currentscore = 0;
	game->steps = 0;
	game->wall.height = SIZE_PXL;
	game->wall.width = SIZE_PXL;
	game->ground.height = SIZE_PXL;
	game->ground.width = SIZE_PXL;
	game->bunker.height = SIZE_PXL;
	game->bunker.width = SIZE_PXL;
	game->dfs.is_collectable = 0;
	game->dfs.is_exit = 0;
	game->dfs.tmp_x = 0;
	game->dfs.tmp_y = 0;
	set_tmp_dfs_map(game);
	return (0);
}
