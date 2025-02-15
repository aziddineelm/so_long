/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-mans <ael-mans@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 18:52:31 by ael-mans          #+#    #+#             */
/*   Updated: 2025/02/15 19:18:27 by ael-mans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stddef.h>
# include <mlx.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <stddef.h>
# include <unistd.h>

# define BUFFER_SIZE 10
# define COLLECTIBLE 1

typedef struct s_data
{
	void	*mlx;
	void	*window;
	char	*filename;
	char	**map;
	int		coloms;
	int		rows;
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
int	is_rectangle(t_data data);

#endif
