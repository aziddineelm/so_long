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

int	movement(int keycode, t_data *data)
{
	if (keycode == 65307)
		close_window(keycode, data);
	if (keycode == 65362)
		data->player_y--;
	else if (keycode == 65361)
		data->player_y++;
	else if (keycode == 65363)
		data->player_x--;
	else if (keycode == 65364)
		data->player_x++;

	render_image(data);
	return (0);
}
