/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akanbari <akanbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 20:19:16 by akanbari          #+#    #+#             */
/*   Updated: 2023/11/06 19:59:33 by akanbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <limits.h>

int		check_new_line(char *buf);
int		read_buf(char **buf, char **static_array, int fd);
char	*ft_strndup(const char *s, int n);
int		ft_gstrlen(char *str);
char	*get_the_line(char **array, int char_read, int line_to_newline);
char	*get_next_line(int fd);
char	*strnjoin(char **array, char **buf);
#endif
