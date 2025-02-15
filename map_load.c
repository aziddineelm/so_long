/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_load.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-mans <ael-mans@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 15:27:53 by ael-mans          #+#    #+#             */
/*   Updated: 2025/02/15 19:27:46 by ael-mans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

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

char	**read_map(t_data *data)
{
	int		fd;
	char	*line;
	int		i;

	fd = open(data->filename, O_RDONLY);
	if (fd < 0)
		return (NULL);
	data->rows = rows_calc(data->filename);
	data->map = (char **)malloc(sizeof(char *) * (data->rows) + 1);
	if (!data->map)
		return (NULL);
	i = 0;
	line = get_next_line(fd);
	data->coloms = (ft_strlen(line) - 1);
	while (line)
	{
		data->map[i++] = line;
		line = get_next_line(fd);
	}
	data->map[i] = NULL;
	return (close(fd), data->map);
}
