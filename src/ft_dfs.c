/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dfs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akanbari <akanbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 22:47:03 by akanbari          #+#    #+#             */
/*   Updated: 2023/11/22 22:46:54 by akanbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

//here i have to create a second test map that is has all zeros,
//and i will gonna go throug my original map
//if i am in a free space , i will check if i can go up,down,left or right, 
//if i visited an available position,
//i will set it to 1 in my tmp map, and i will check for all collectables
//if i can collect them because i fount 
//the path to exit // the 'v' letter in the second map to check 
//if the postion is visited and '0' refers that the position is
//not visited
//dfs is a type of graph traversal algorithm, where it is an algorithm to visit
//every vertex of a graph 
/*Depth-first search is an algorithm for traversing or searching tree 
or graph data structures. The algorithm starts at the root node (selecting some 
arbitrary node as the root node in the case of a graph) and explores as far 
as possible along each branch before backtracking.*/

int	validcheck(t_mygame *game, int x, int y)
{
	if (game->dfs.tmp_map[y][x] == 'v')
		return (1);
	if (game->map[y][x] == '1')
		return (1);
	return (0);
}

void	ft_dfs(t_mygame *game, int x, int y)
{
	game->dfs.tmp_map[y][x] = 'v';
	if (game->map[y][x] == 'C')
		game->dfs.is_collectable++;
	if (game->map[y][x] == 'E')
		game->dfs.is_exit++;
	if (validcheck(game, x, y - 1) == 0)
		ft_dfs(game, x, y - 1);
	if (validcheck(game, x + 1, y) == 0)
		ft_dfs(game, x + 1, y);
	if (validcheck(game, x, y + 1) == 0)
		ft_dfs(game, x, y + 1);
	if (validcheck(game, x - 1, y) == 0)
		ft_dfs(game, x - 1, y);
}
