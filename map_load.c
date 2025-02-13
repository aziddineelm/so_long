/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_load.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-mans <ael-mans@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 15:27:53 by ael-mans          #+#    #+#             */
/*   Updated: 2025/02/13 18:02:48 by ael-mans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	rows_calc(char *map_file)
{
	int		i;
	int		fd;
	char	*line;

	i = 0;
	fd = open(map_file, O_RDONLY);
	if (fd < 0)
		return (0);
	line = get_next_line(fd);
	while (line)
	{
		line = get_next_line(fd);
		free(line);
		i++;
	}
	close(fd);
	return (i);
}

char	**read_map(char *map_file, int *rows)
{
	int		fd;
	char	*line;
	char	**map;
	int		i;

	fd = open(map_file, O_RDONLY);
	if (fd < 0)
		return (NULL);
	*rows = rows_calc(map_file);
	map = (char **)malloc(sizeof(char *) * *rows + 1);
	if (!map)
		return (NULL);
	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		map[i++] = line;
		line = get_next_line(fd);
	}
	map[i] = NULL;
	return (close(fd), map);
}
