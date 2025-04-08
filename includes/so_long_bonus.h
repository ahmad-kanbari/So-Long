/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akanbari <akanbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 17:39:41 by akanbari          #+#    #+#             */
/*   Updated: 2023/11/23 19:26:14 by akanbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

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
// Eat your Bugs
# define GAME_NAME  	"eat your bugs"
# define SIZE_PXL		40
# define HERO_UP0   	"./img/bugs/tarantula/up/0.xpm"
# define HERO_UP1   	"./img/bugs/tarantula/up/1.xpm"
# define HERO_UP2   	"./img/bugs/tarantula/up/2.xpm"
# define HERO_UP3   	"./img/bugs/tarantula/up/3.xpm"

# define HERO_DOWN0   	"./img/bugs/tarantula/down/0.xpm"
# define HERO_DOWN1   	"./img/bugs/tarantula/down/1.xpm"
# define HERO_DOWN2   	"./img/bugs/tarantula/down/2.xpm"
# define HERO_DOWN3   	"./img/bugs/tarantula/down/3.xpm"

# define HERO_LEFT0   	"./img/bugs/tarantula/left/0.xpm"
# define HERO_LEFT1   	"./img/bugs/tarantula/left/1.xpm"
# define HERO_LEFT2   	"./img/bugs/tarantula/left/2.xpm"
# define HERO_LEFT3   	"./img/bugs/tarantula/left/3.xpm"

# define HERO_RIGHT0   	"./img/bugs/tarantula/right/0.xpm"
# define HERO_RIGHT1   	"./img/bugs/tarantula/right/1.xpm"
# define HERO_RIGHT2   	"./img/bugs/tarantula/right/2.xpm"
# define HERO_RIGHT3   	"./img/bugs/tarantula/right/3.xpm"

# define GROUND 	"./img/bugs/sand.xpm"
# define BORDER		"./img/bugs/cactus.xpm"
# define EXIT		"./img/bugs/hovel.xpm"
# define ITEM		"./img/bugs/bugs/bug1.xpm"

# define ENEMY1   	"./img/bugs/enemy/0.xpm"
# define ENEMY2   	"./img/bugs/enemy/1.xpm"
# define ENEMY3   	"./img/bugs/enemy/2.xpm"

# define FINISH		"./img/bugs/game_over/0.xpm"

# define SPEED 100000

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

typedef struct s_sprite
{
	char	*path;
	int		width;
	int		height;
	int		pos_y;
	int		pos_x;
	void	*img;
}	t_sprite;

typedef struct s_heroanime
{
	int			hero;
	int			width;
	int			height;
	int			photo_counter;
	t_sprite	up[4];
	t_sprite	down[4];
	t_sprite	left[4];
	t_sprite	right[4];
}	t_heroanime;

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

typedef struct s_hero
{
	int		hero;
	int		width;
	int		height;
	char	*path;
	void	*img;
}	t_hero;

typedef struct s_enemy
{
	int			enemy_count;
	int			i_counter;
	int			width;
	int			height;
	int			direction[3];
	t_sprite	enemies[3];
}	t_enemy;

typedef struct t_list
{
	t_vars			vars;
	t_heroanime		hero;
	t_enemy			enemy;
	t_collect		item;
	t_sprite		wall;
	t_sprite		bunker;
	t_sprite		ground;
	t_msize			map_size;
	t_dfs			dfs;
	t_sprite		finish;
	int				exit;
	int				steps;
	int				position_x;
	int				position_y;
	int				score;
	int				movement_flag;
	int				currentscore;
	int				exit_y;
	int				exit_x;
	char			**map;
	char			*maplink;
	char			*mapcontent;
}	t_mygame;

int			check_ber(t_mygame *game);
int			ft_savemap(t_mygame *game);
int			isrectangle(t_mygame *game);
int			ft_check_surr_walls(t_mygame *game);
int			initialize_game(t_mygame *game);
int			load_objects_tomlx(t_mygame *game);
int			draw_map(t_mygame *game);
int			finish_game_won(t_mygame *game);
int			finish_game_lost(t_mygame *game);
int			set_variables(t_mygame *game);
void		move_up_utill_0(t_mygame *game);
void		move_down_utill_0(t_mygame *game);
void		move_left_utill_0(t_mygame *game);
void		move_right_utill_0(t_mygame *game);
int			move_up(t_mygame *game);
int			move_down(t_mygame *game);
int			move_left(t_mygame *game);
int			move_right(t_mygame *game);
int			checking_map(t_mygame *game);
void		ft_dfs(t_mygame *game, int x, int y);
int			set_tmp_dfs_map(t_mygame *game);
int			unload_objects(t_mygame *game);
int			set_variables2(t_mygame *game);
void		ft_putimage(t_mygame *game, void *img, int position_y, \
				int position_x);
void		check_paths(t_mygame *game);
void		*convert_xpm(t_mygame *game, char *path);
int			finish_game(t_mygame *game);
int			move_enemy_down(t_mygame *game, int j, int i, int enemy_id);
int			move_enemy_up(t_mygame *game, int j, int i, int enemy_id);
int			move_enemy_right(t_mygame *game, int j, int i, int enemy_id);
int			move_enemy_left(t_mygame *game, int j, int i, int enemy_id);
int			generate_random_number(int min, int max);
int			update_window(t_mygame *game);

#endif