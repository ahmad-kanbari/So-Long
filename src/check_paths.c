/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_paths.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akanbari <akanbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 22:57:01 by akanbari          #+#    #+#             */
/*   Updated: 2023/11/23 15:17:53 by akanbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	check_paths(t_mygame *game)
{
	if (game->ground.img == NULL)
		return (ft_printf("Wrong XPM File"), exit(1));
	if (game->wall.img == NULL)
		return (ft_printf("Wrong XPM File"), exit(1));
	if (game->bunker.img == NULL)
		return (ft_printf("Wrong XPM File"), exit(1));
	if (game->item.img == NULL)
		return (ft_printf("Wrong XPM File"), exit(1));
	if (game->hero.img == NULL)
		return (ft_printf("Wrong XPM File"), exit(1));
}
