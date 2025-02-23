/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-mans <ael-mans@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 17:52:55 by ael-mans          #+#    #+#             */
/*   Updated: 2025/02/22 13:01:52 by ael-mans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_map(t_data *data)
{
	if (name_check(data->filename))
		exit_error("Error!\nPlease Enter a valid map with \".ber\"\n");
	data->map = read_map(data);
	if (!data->map)
		free_error(("Error\nMap could not be read\n"), data);
	if (is_rectangle(data))
		free_error(("Error\nMap is not a rectangle!\n"), data);
	if (surrounded_by_walls(data))
		free_error(("Error\nMap not surrounded by walls!\n"), data);
	if (has_required_element(data))
		free_error(("Error\nMap has invalid element count!\n"), data);
	if (has_valid_path(data))
		free_error(("Error\nNo valid path!\n"), data);
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 2)
		return (1);
	data.filename = av[1];
	data.columns = 0;
	check_map(&data);
	data.mlx = mlx_init();
	if (!data.mlx)
		free_error("Error\nMLX initialization failed\n", &data);
	data.window = mlx_new_window(data.mlx, data.columns * 32, data.rows * 32, "so_long");
	data.width = 0;
	data.height = 0;
	load_image(&data);
	render_image(&data);
	mlx_hook(data.window, 2, 1L<<0, movement, &data);
	mlx_hook(data.window, 17, 0, close_x_window, &data);
	mlx_loop(data.mlx);
	return (0);
}
