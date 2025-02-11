/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   name_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-mans <ael-mans@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 20:37:18 by ael-mans          #+#    #+#             */
/*   Updated: 2025/02/10 21:22:41 by ael-mans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

int	name_check(char *map)
{
	size_t	len;

	len = ft_strlen(map);
	if (len < 5 || ft_strcmp(map + len - 4, ".ber") != 0)
		return (1);
	return (0);
}

char	**read_map(char *map_file)
{
	int		fd;
	char	*line;
	char	**map;
	int		i;
	t_data	data;

	fd = open(map_file, O_RDONLY);
	if (fd < 0)
		return (NULL);
	map = (char **)malloc(sizeof(char *) * 20);
	if (!map)
		return (NULL);
	i = 0;
	line = get_next_line(fd);
	while(line)
	{
		map[i] = line;
		free(line);
		i++;
		line = get_next_line(fd);
	}
	map[i] = NULL;
	close(fd);
	return (map);
}
