/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movemnts.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-mans <ael-mans@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 12:06:49 by ael-mans          #+#    #+#             */
/*   Updated: 2025/02/22 13:07:03 by ael-mans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_up(t_data *data)
{

	if (data->map[data->player_x - 1][data->player_y] != '1')
	{
		data->map[data->player_x][data->player_y] = '0';
		data->player_x--;
		data->map[data->player_x][data->player_y] = 'P';
	}
}

void	move_down(t_data *data)
{
	if (data->map[data->player_x + 1][data->player_y] != '1')
	{
		data->map[data->player_x][data->player_y] = '0';
		data->player_x++;
		data->map[data->player_x][data->player_y] = 'P';
	}
}

void	move_left(t_data *data)
{
	if (data->map[data->player_x][data->player_y - 1] != '1')
	{
		data->map[data->player_x][data->player_y] = '0';
		data->player_y--;
		data->map[data->player_x][data->player_y] = 'P';
	}
}

void	move_right(t_data *data)
{
	if (data->map[data->player_x][data->player_y + 1] != '1')
	{
		data->map[data->player_x][data->player_y] = '0';
		data->player_y++;
		data->map[data->player_x][data->player_y] = 'P';
	}
}

int	movement(int keycode, t_data *data)
{
	if (keycode == 65307)
		close_window(keycode, data);
	if (keycode == 65362 || keycode == 119)
		move_up(data);
	if (keycode == 65364 || keycode == 115)
		move_down(data);
	if (keycode == 65361 || keycode == 97)
		move_left(data);
	if (keycode == 65363 || keycode == 100)
		move_right(data);
	render_image(data);
	return (0);
}
