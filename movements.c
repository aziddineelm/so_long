/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movemnts.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-mans <ael-mans@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 12:06:49 by ael-mans          #+#    #+#             */
/*   Updated: 2025/02/23 10:36:53 by ael-mans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	handle_exit_move(t_data *data, int new_x, int new_y, char curr)
{
	if (data->collectible == 0)
	{
		ft_putstr("Congratulations! You won!\n");
		close_window(data);
	}
	if (curr != 'E')
		data->map[data->player_x][data->player_y] = '0';
	data->player_x = new_x;
	data->player_y = new_y;
}

void	handle_normal_move(t_data *data, int new_x, int new_y, char curr)
{
	char	next;

	next = data->map[new_x][new_y];
	if (next == 'C')
		data->collectible--;
	if (curr == 'E')
		data->map[data->player_x][data->player_y] = 'E';
	else
		data->map[data->player_x][data->player_y] = '0';
	data->player_x = new_x;
	data->player_y = new_y;
	data->map[new_x][new_y] = 'P';
}

void	handle_move_outcome(t_data *data, int new_x, int new_y)
{
	char	next;
	char	curr;

	curr = data->map[data->player_x][data->player_y];
	next = data->map[new_x][new_y];
	if (next == 'X')
	{
		ft_putstr("Game Over! You hit an enemy!\n");
		close_window(data);
	}
	else if (next == 'E')
		handle_exit_move(data, new_x, new_y, curr);
	else
		handle_normal_move(data, new_x, new_y, curr);
}

void	process_move(t_data *data, int dx, int dy)
{
	int	new_x;
	int	new_y;

	new_x = data->player_x + dx;
	new_y = data->player_y + dy;
	if (data->map[new_x][new_y] != '1')
	{
		data->moves_count++;
		handle_move_outcome(data, new_x, new_y);
	}
}

int	movement(int keycode, t_data *data)
{
	if (keycode == 65307)
		close_window(data);
	else if (keycode == 65362 || keycode == 119)
		process_move(data, -1, 0);
	else if (keycode == 65364 || keycode == 115)
		process_move(data, 1, 0);
	else if (keycode == 65361 || keycode == 97)
		process_move(data, 0, -1);
	else if (keycode == 65363 || keycode == 100)
		process_move(data, 0, 1);
	render_image(data);
	put_moves(data);
	return (0);
}
