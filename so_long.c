/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-mans <ael-mans@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 17:52:55 by ael-mans          #+#    #+#             */
/*   Updated: 2025/02/17 12:39:08 by ael-mans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	exit_error(char *msg, t_data *data)
{
	ft_putstr(msg);
	free_map(data->map, data->rows);
	exit(1);
}

void	check_map(t_data *data)
{
	if (name_check(data->filename))
		ft_putstr("Error!\nPlease Enter a valid map with \".ber\"\n");
	data->map = read_map(data);
	if (!data->map)
		exit_error(("Error\nMap could not be read\n"), data);
	if (is_rectangle(data))
		exit_error(("Error\nMap is not a rectangle!\n"), data);
	if (surrounded_by_walls(data))
		exit_error(("Error\nMap not surrounded by walls!\n"), data);
	if (has_required_element(data))
		exit_error(("Error\nMap has invalid element count!\n"), data);
	if (has_valid_path(data))
		exit_error(("Error\nNo valid path!\n"), data);
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
	data.window = mlx_new_window(data.mlx, 740, 480, "so_long");
	mlx_key_hook(data.window, close_window, &data);
	mlx_hook(data.window, 17, 0, close_x_window, &data);
	mlx_loop(data.mlx);
	return (0);
}
