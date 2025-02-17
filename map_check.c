/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-mans <ael-mans@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 20:37:18 by ael-mans          #+#    #+#             */
/*   Updated: 2025/02/17 12:38:09 by ael-mans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	name_check(char *filename)
{
	size_t	len;

	len = ft_strlen(filename);
	if (len < 5)
	{
		ft_putstr("Error!\nPlease Enter at least 1 character with \".ber\"");
		return (1);
	}
	if (ft_strcmp(filename + len - 4, ".ber") != 0)
		return (1);
	return (0);
}

int	is_rectangle(t_data *data)
{
	int	i;
	int	line_len;

	i = 0;
	while (i < data->rows)
	{
		line_len = ft_strlen(data->map[i]);
		if (line_len > 0 && data->map[i][line_len - 1] == '\n')
			line_len--;
		if (line_len != data->columns)
			return (1);
		i++;
	}
	return (0);
}

int	surrounded_by_walls(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->columns)
	{
		if (data->map[0][i] != '1' || data->map[data->rows - 1][i] != '1')
			return (1);
		i++;
	}
	i = 0;
	while (i < data->rows)
	{
		if (data->map[i][0] != '1' || data->map[i][data->columns - 1] != '1')
			return (1);
		i++;
	}
	return (0);
}

int	count_elements(t_data *data)
{
	int	i;
	int	j;

	data->collectible = 0;
	data->player = 0;
	data->exit = 0;
	i = -1;
	while (++i < data->rows)
	{
		j = -1;
		while (++j < data->columns)
		{
			if (data->map[i][j] == 'C')
				data->collectible++;
			else if (data->map[i][j] == 'P')
				data->player++;
			else if (data->map[i][j] == 'E')
				data->exit++;
			else if (data->map[i][j] != '0' && data->map[i][j] != '1'
				&& data->map[i][j] != 'X')
				return (ft_putstr("Error\nMap contains \
				invalid characters!"),
						1);
		}
	}
	return (0);
}

int	has_required_element(t_data *data)
{
	if (count_elements(data))
		return (1);
	if (data->exit != 1 || data->player != 1 || data->collectible < 1)
	{
		ft_putstr("Error\nInvalid element count");
		return (1);
	}
	return (0);
}
