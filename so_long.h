/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-mans <ael-mans@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 18:52:31 by ael-mans          #+#    #+#             */
/*   Updated: 2025/02/09 11:04:41 by ael-mans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include <stddef.h>
# include <mlx.h>
# include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <stddef.h>
#include <unistd.h>

# define BUFFER_SIZE 32
# define COLLECTIBLE 1


char	*ft_read(char *buffer, int fd);
char	*get_next_line(int fd);
int	ft_contain(char *str, int c);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(char *s);
int	ft_strlen(char *s);

typedef struct s_data
{
	void	*mlx;
	void	*window;
}			t_data;

#endif
