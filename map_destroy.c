/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_destroy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-mans <ael-mans@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 10:49:45 by ael-mans          #+#    #+#             */
/*   Updated: 2025/02/22 12:55:42 by ael-mans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(char **map, int rows)
{
	int	i;

	i = 0;
	if (!map)
		return ;
	while (i < rows && map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	free_image(t_data *data)
{
	if (data->coin_img)
		mlx_destroy_image(data->mlx, data->coin_img);
	if (data->exit_img)
		mlx_destroy_image(data->mlx, data->exit_img);
	if (data->wall_img)
		mlx_destroy_image(data->mlx, data->wall_img);
	if (data->enemy_img)
		mlx_destroy_image(data->mlx, data->enemy_img);
	if (data->floor_img)
		mlx_destroy_image(data->mlx, data->floor_img);
	if (data->player_img)
		mlx_destroy_image(data->mlx, data->player_img);
}

int	close_window(t_data *data)
{
	mlx_destroy_window(data->mlx, data->window);
	free_image(data);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	free_map(data->map, data->rows);
	exit(0);
	return (0);
}

int	close_x_window(void *ptr)
{
	t_data	*data;

	data = (t_data *)ptr;
	mlx_destroy_window(data->mlx, data->window);
	free_image(data);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	free_map(data->map, data->rows);
	exit(0);
}
