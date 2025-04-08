# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akanbari <akanbari@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/07 18:56:29 by akanbari          #+#    #+#              #
#    Updated: 2023/11/23 18:59:36 by akanbari         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=		so_long

SRCS	=		./src/so_long.c \
				./src/checkers_utilities.c \
				./src/savemap.c \
				./src/movements.c \
				./src/move_helpers.c \
				./src/helper_functions.c \
				./src/ft_dfs.c \
				./src/checkers2_utilities.c \
				./src/check_paths.c \
				./src/movements2.c \

BONUS_SRCS	= 	./src_bonus/so_long_bonus.c \
				./src_bonus/checkers_utilities_bonus.c \
				./src_bonus/savemap_bonus.c \
				./src_bonus/movements_up_bonus.c \
				./src_bonus/movements_down_bonus.c \
				./src_bonus/movements_left_bonus.c \
				./src_bonus/movements_right_bonus.c \
				./src_bonus/move_helpers_bonus.c \
				./src_bonus/helper_functions_bonus.c \
				./src_bonus/ft_dfs_bonus.c \
				./src_bonus/checkers2_utilities_bonus.c \
				./src_bonus/convertors_bonus.c \
				./src_bonus/enemy.c \
				./src_bonus/ft_finish_bonus.c \
				./src_bonus/update_window.c \
				./src_bonus/initializer.c \
				./src_bonus/draw_map.c \

FLAGS	=		-fsanitize=address -Wall -Werror -Wextra -Imlx -g3

LIBFT	=		libraries/ft_libft/libft.a

MLX		=		libraries/mlx/libmlx.a

OBJS	=		$(SRCS:%.c=%.o)

BONUS_OBJS =	$(BONUS_SRCS:%.c=%.o)

ifdef WITH_BONUS
ALL_OBJS = $(BONUS_OBJS)
HEADER	=		includes/so_long.h

else
ALL_OBJS = $(OBJS)
HEADER	=		includes/so_long_bonus.h

endif

all: $(LIBFT) $(MLX) $(NAME)

$(NAME): $(ALL_OBJS) $(LIBFT) $(MLX)
	$(CC) ${FLAGS} $^ -framework OpenGL -framework AppKit -o $(NAME)

bonus: 
	$(MAKE) WITH_BONUS=1

%.o: %.c $(HEADER)
	$(CC) $(FLAGS) -c $< -o $@

#create a libft and create a symbolic link to the libft.a library
#test -e libft.a: This command checks whether the file libft.a 
#exists in the current directory. The -e flag is used to test for existence.
#Try to build the libft library using make in the specified directory. If successful, check if libft.a exists in the current directory. If it doesn't exist, create a symbolic link to libraries/ft_libft/libft.a named libft.a." This ensures that the libft.a file is available in the project's main directory, 
#either through direct existence or a symbolic link.
$(LIBFT):
	$(MAKE) -C libraries/ft_libft && test -e libft.a || ln -sf libraries/ft_libft/libft.a libft.a

$(MLX):
	$(MAKE) -C libraries/mlx && test -e libmlx.a || ln -sf libraries/mlx/libmlx.a libmlx.a

clean:
	make clean -C libraries/ft_libft
	make clean -C libraries/mlx
	rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	rm -f $(MLX)
	rm -f $(LIBFT)
	rm -f $(NAME)
	rm -f libmlx.dylib
	rm -f libmlx.a
	rm -f libft.a

re: fclean all

rebonus : fclean bonus