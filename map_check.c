/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-mans <ael-mans@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 20:37:18 by ael-mans          #+#    #+#             */
/*   Updated: 2025/02/15 19:28:53 by ael-mans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	name_check(char *filename)
{
	size_t	len;

	len = ft_strlen(filename);
	if (ft_strcmp(filename + len - 4, ".ber") != 0)
		return (1);
	if (len < 5)
	{
		ft_putstr("Error!\nPlease Enter at least 1 character with \".ber\"");
		return (1);
	}
	return (0);
}

int	is_rectangle(t_data *data)
{
	int	i;

	i = 0;
	while (data->map[i])
	{
		if ((ft_strlen(data->map[i]) - 1) != data->coloms)
			return (1);
		i++;
	}
	return (0);
}

int	surrounded_by_walls(t_data *data)
{
	int	i;

	i = 0;
	while(i < data->coloms)
	{
		if (data->map[0][i] != '1' || data->map[data->rows - 1][i] != '1')
			return (1);
		i++;
	}
	i = 0;
	while (i < data->rows)
	{
		if (data->map[i][0] != '1' || data->map[i][data->coloms - 1] != '1')
			return (1);
		i++;
	}
	return (0);
}

int	has_require_element(t_data *data)
{
	int	i;
	int	j;

	data->collectible = 0;
	data->exit = 0;
	data->player = 0;
	i = 0;
	while(i < data->rows)
	{
		j = 0;
		while(j < data->coloms)
		{
			if (data->map[i][j] == 'C')
				data->collectible++;
			if (data->map[i][j] == 'P')
				data->player++;
			if (data->map[i][j] == 'E')
				data->exit++;
			j++;
		}
		i++;
	}
	if (data->exit != 1 || data->player != 1 || data->collectible < 1)
	{
		ft_putstr("Error\nMap must have at least one collectible, one player, and one exit!");
		return (1);
	}
	return (0);
}
