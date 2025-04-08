/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   savemap_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akanbari <akanbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 22:08:17 by akanbari          #+#    #+#             */
/*   Updated: 2023/11/23 16:35:25 by akanbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

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
