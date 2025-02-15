/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-mans <ael-mans@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 17:52:55 by ael-mans          #+#    #+#             */
/*   Updated: 2025/02/15 19:19:06 by ael-mans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"



int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 2)
		return (1);
	data.filename = av[1];
	if (!name_check(data.filename))
		return (ft_putstr("Error!\nPlease Entre a valid map\n"), 1);
	data.map = read_map(&data);
	if (!data.map)
		return (1);
	print_map(data.map);
	is_rectangle(data);
	data.mlx = mlx_init();
	data.window = mlx_new_window(data.mlx, 740, 480, "so_long");
	mlx_key_hook(data.window, close_window, &data);
	mlx_hook(data.window, 17, 0, close_x_window, 0);
	mlx_loop(data.mlx);
	return (0);
}
