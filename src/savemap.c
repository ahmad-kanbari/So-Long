/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   savemap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akanbari <akanbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 22:08:17 by akanbari          #+#    #+#             */
/*   Updated: 2023/11/23 15:13:28 by akanbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	ft_savemap_helper(t_mygame *game)
{
	int	fd;

	game->map = (char **)malloc(sizeof(char *) * (game->vars.size_y + 1));
	fd = open(game->maplink, O_RDONLY);
	game->vars.size_x = 0;
	while (game->vars.size_x < game->vars.size_y)
	{
		game->map[game->vars.size_x] = get_next_line(fd);
		game->vars.size_x++;
	}
	game->map[game->vars.size_x] = 0;
	close(fd);
}

int	ft_savemap(t_mygame *game)
{
	int	fd;

	fd = open(game->maplink, O_RDONLY);
	if (fd == -1)
		return (ft_printf("Wrong file name \n"), exit(1), 0); 
	game->vars.size_y = 0;
	game->mapcontent = get_next_line(fd);
	if (game->mapcontent == NULL)
		return (ft_printf("File is empty \n"), exit(1), 0); 
	while (game->mapcontent)
	{
		free(game->mapcontent);
		game->mapcontent = get_next_line(fd);
		game->vars.size_y++;
	}
	close(fd);
	ft_savemap_helper(game);
	return (0);
}

int	draw_map2_helper(t_mygame *game, int i, int j)
{
	if (game->map[i][j] == '1')
	{
		mlx_put_image_to_window(game->vars.mlx, game->vars.window, \
		game->ground.img, (j * SIZE_PXL), (i * SIZE_PXL));
		mlx_put_image_to_window(game->vars.mlx, game->vars.window, \
		game->wall.img, (j * SIZE_PXL), (i * SIZE_PXL));
	}
	else if (game->map[i][j] == '0')
		mlx_put_image_to_window(game->vars.mlx, game->vars.window, \
		game->ground.img, (j * SIZE_PXL), (i * SIZE_PXL));
	return (1);
}

int	draw_map2(t_mygame *game, int i, int j)
{
	draw_map2_helper(game, i, j);
	if (game->map[i][j] == 'P')
	{
		mlx_put_image_to_window(game->vars.mlx, game->vars.window, \
		game->ground.img, (j * SIZE_PXL), (i * SIZE_PXL));
		mlx_put_image_to_window(game->vars.mlx, game->vars.window, \
		game->hero.img, (j * SIZE_PXL), (i * SIZE_PXL));
	}
	else if (game->map[i][j] == 'E')
	{
		mlx_put_image_to_window(game->vars.mlx, game->vars.window, \
		game->ground.img, (j * SIZE_PXL), (i * SIZE_PXL));
		mlx_put_image_to_window(game->vars.mlx, game->vars.window, \
		game->bunker.img, (j * SIZE_PXL), (i * SIZE_PXL));
	}
	else if (game->map[i][j] == 'C')
	{
		mlx_put_image_to_window(game->vars.mlx, game->vars.window, \
		game->ground.img, (j * SIZE_PXL), (i * SIZE_PXL));
		mlx_put_image_to_window(game->vars.mlx, game->vars.window, \
		game->item.img, (j * SIZE_PXL), (i * SIZE_PXL));
	}
	if (game->hero.img == NULL)
		return (ft_printf("Wrong XPM File"), exit(1), 0);
	return (1);
}

int	draw_map(t_mygame *game)
{
	int	i;
	int	j;

	i = -1;
	while (game->map[++i])
	{
		j = -1;
		while (game->map[i][++j])
			draw_map2(game, i, j);
	}
	return (0);
}
