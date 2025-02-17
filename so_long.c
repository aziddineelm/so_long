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

int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 2)
		return (1);
	data.filename = av[1];
	if (name_check(data.filename))
		return (ft_putstr("Error!\nPlease Entre a valid map with \".ber\"\n"),
			1);
	data.map = read_map(&data);
	if (!data.map)
		return (1);
	if (is_rectangle((&data)))
	{
		ft_putstr("Error\nmap is not rectangle!");
		return (1);
	}
	if (surrounded_by_walls(&data))
	{
		ft_putstr("Error\nMap not surrounded by walls!!");
		return (1);
	}
	if (has_required_element(&data))
	{
		return (1);
	}
	if (has_valid_path(&data))
		return (1);
	data.mlx = mlx_init();
	data.window = mlx_new_window(data.mlx, 740, 480, "so_long");
	mlx_key_hook(data.window, close_window, &data);
	mlx_hook(data.window, 17, 0, close_x_window, &data);
	mlx_loop(data.mlx);
	return (0);
}
