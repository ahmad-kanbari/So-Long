/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akanbari <akanbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 17:39:41 by akanbari          #+#    #+#             */
/*   Updated: 2023/11/23 19:26:38 by akanbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libraries/ft_libft/includes/libft.h"
# include "../libraries/ft_libft/includes/get_next_line.h"
# include "../libraries/ft_libft/includes/ft_printf.h"
# include "../libraries/mlx/mlx.h"

# define W		13
# define S		1
# define A		0
# define D      2

# define ESC	53

# define UP 126
# define DOWN 125
# define LEFT 123
# define RIGHT 124

# define HERO   	"./img/bugs/tarantula/up/0.xpm"
# define GROUND 	"./img/bugs/sand.xpm"
# define BORDER		"./img/bugs/cactus.xpm"
# define EXIT		"./img/bugs/hovel.xpm"
# define ITEM		"./img/bugs/bugs/bug1.xpm"
# define GAME_NAME  "Eat Your Bugs"

//define the size of the image pixels your are trying to create
# define SIZE_PXL	40

//size_x for number of letters in 1 line in a map
//size_y for number of lines in a map
typedef struct s_vars
{
	void	*mlx;
	void	*window;
	int		size_x;
	int		size_y;
}				t_vars;

typedef struct s_mapsize
{
	int		w;
	int		h;
}	t_msize;

typedef struct s_hero
{
	int		hero;
	int		width;
	int		height;
	char	*path;
	void	*img;
}	t_hero;

typedef struct s_sprite
{
	char	*path;
	int		width;
	int		height;
	void	*img;
}	t_sprite;

typedef struct s_collect
{
	char	*path;
	int		width;
	int		height;
	void	*img;
	int		item;
}	t_collect;

typedef struct s_dfs
{
	char	**tmp_map;
	int		is_collectable;
	int		is_exit;
	int		tmp_x;
	int		tmp_y;
}	t_dfs;

typedef struct t_list
{
	t_vars			vars;
	t_hero			hero;
	t_hero			enemy;
	t_collect		item;
	t_sprite		wall;
	t_sprite		bunker;
	t_sprite		ground;
	t_msize			map_size;
	t_dfs			dfs;
	int				exit;
	int				exit_y;
	int				exit_x;
	int				steps;
	int				position_x;
	int				position_y;
	int				score;
	int				currentscore;
	char			**map;
	char			*maplink;
	char			*mapcontent;
}	t_mygame;

int		check_ber(t_mygame *game);
int		ft_savemap(t_mygame *game);
int		isrectangle(t_mygame *game);
int		ft_check_surr_walls(t_mygame *game);
int		initialize_game(t_mygame *game);
int		load_objects_tomlx(t_mygame *game);
int		draw_map(t_mygame *game);
int		finish_game(t_mygame *game);
int		set_variables(t_mygame *game);
void	move_up_utill_0(t_mygame *game);
void	move_down_utill_0(t_mygame *game);
void	move_left_utill_0(t_mygame *game);
void	move_right_utill_0(t_mygame *game);
int		move_up(t_mygame *game);
int		move_down(t_mygame *game);
int		move_left(t_mygame *game);
int		move_right(t_mygame *game);
int		checking_map(t_mygame *game);
void	ft_dfs(t_mygame *game, int x, int y);
int		unload_objects(t_mygame *game);
int		set_value(int *num, int value, int set);
void	ft_putimage(t_mygame *game, void *img, \
		int position_y, int position_x);
void	check_paths(t_mygame *game);

#endif