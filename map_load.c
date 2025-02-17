/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_load.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-mans <ael-mans@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 15:27:53 by ael-mans          #+#    #+#             */
/*   Updated: 2025/02/17 12:34:47 by ael-mans         ###   ########.fr       */
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
		i++;
		free(line);
		line = get_next_line(fd);
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
	data->map = (char **)malloc(sizeof(char *) * (data->rows + 1));
	if (!data->map)
		return (close(fd), NULL);
	i = 0;
	line = get_next_line(fd);
	if (!line)
		return (ft_putstr("Error\nMap is empty"), \
		free(data->map), close(fd), NULL);
	while (line)
	{
		if (data->columns == 0)
			data->columns = ft_strlen(line) - (line[ft_strlen(line) - 1] == '\n');
		data->map[i++] = line;
		line = get_next_line(fd);
	}
	data->map[i] = NULL;
	return (free(line), close(fd), data->map);
}
