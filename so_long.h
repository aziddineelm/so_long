/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-mans <ael-mans@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 18:52:31 by ael-mans          #+#    #+#             */
/*   Updated: 2025/02/11 10:50:59 by ael-mans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include <stddef.h>
#include <mlx.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <stddef.h>
#include <unistd.h>

# define BUFFER_SIZE 32
# define COLLECTIBLE 1

typedef struct s_data
{
	void	*mlx;
	void	*window;
	int		rows;
	int		height;
}			t_data;

char	*get_next_line(int fd);
int		ft_contain(char *str, int c);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(char *s);
int		ft_strlen(char *s);
int		ft_strcmp(const char *s1, const char *s2);
int		name_check(char *map);
int		close_window(int keycode, t_data *vars);
int		close_x_window(void *ptr);
void	so_long(char *map);
char	**read_map(char *map_file);

#endif
