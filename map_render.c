/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-mans <ael-mans@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 10:14:38 by ael-mans          #+#    #+#             */
/*   Updated: 2025/02/22 11:10:43 by ael-mans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <mlx.h>

void	load_image(t_data *data)
{
	data->player_img = mlx_xpm_file_to_image(data->mlx, "sprites/player.xpm", &data->width, &data->height);
	data->coin_img = mlx_xpm_file_to_image(data->mlx, "sprites/coin.xpm", &data->width, &data->height);
	data->enemy_img = mlx_xpm_file_to_image(data->mlx, "sprites/enemy.xpm", &data->width, &data->height);
	data->wall_img = mlx_xpm_file_to_image(data->mlx, "sprites/wall.xpm", &data->width, &data->height);
	data->floor_img = mlx_xpm_file_to_image(data->mlx, "sprites/floor.xpm", &data->width, &data->height);
	data->exit_img = mlx_xpm_file_to_image(data->mlx, "sprites/exit.xpm", &data->width, &data->height);
	if (!data->wall_img || !data->player_img || !data->coin_img || !data->exit_img || !data->floor_img || !data->enemy_img)
        free_error("Error loading textures\n", data);
}

void	rendre_image(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->rows)
	{
		x = 0;
		while (x < data->columns)
		{
			if (data->map[y][x] == '1')
				mlx_put_image_to_window(data->mlx, data->window, data->wall_img, data->width * 32, data->height * 32);
			else if (data->map[y][x] == '0')
				mlx_put_image_to_window(data->mlx, data->window, data->floor_img, data->width * 32, data->height * 32);
			else if (data->map[y][x] == 'P')
				mlx_put_image_to_window(data->mlx, data->window, data->player_img, data->width * 32, data->height * 32);
			else if (data->map[y][x] == 'C')
				mlx_put_image_to_window(data->mlx, data->window, data->coin_img, data->width * 32, data->height * 32);
			else if (data->map[y][x] == 'E')
				mlx_put_image_to_window(data->mlx, data->window, data->exit_img, data->width * 32, data->height * 32);
			else if (data->map[y][x] == 'X')
				mlx_put_image_to_window(data->mlx, data->window, data->enemy_img, data->width * 32, data->height * 32);
			x++;
		}
		y++;
	}
}
