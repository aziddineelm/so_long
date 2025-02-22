/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-mans <ael-mans@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 18:52:31 by ael-mans          #+#    #+#             */
/*   Updated: 2025/02/22 10:58:29 by ael-mans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stddef.h>
# include <mlx.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>

# define BUFFER_SIZE 10

typedef struct s_data
{
	void	*mlx;
	void	*window;
	char	*filename;
	char	**map;
	int		columns;
	int		rows;
	int		collectible;
	int		exit;
	int		player;
	int		player_x;
	int		player_y;
	int		width;
	int		height;
	void	*player_img;
	void	*floor_img;
	void	*coin_img;
	void	*wall_img;
	void	*enemy_img;
	void	*exit_img;
}			t_data;

void	print_map(char **map);
char	*get_next_line(int fd);
int		ft_contain(char *str, int c);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(char *s);
int		ft_strlen(char *s);
int		ft_strcmp(const char *s1, const char *s2);
int		name_check(char *filename);
int		close_window(int keycode, t_data *vars);
int		close_x_window(void *ptr);
char	**read_map(t_data *data);
void	ft_putstr(char *str);
int		is_rectangle(t_data *data);
int		surrounded_by_walls(t_data *data);
int		has_required_element(t_data *data);
int		has_valid_path(t_data *data);
void	free_map(char **map, int rows);
void	exit_error(char *msg);
void	free_error(char *msg, t_data *data);
void	rendre_image(t_data *data);
void	load_image(t_data *data);

#endif
