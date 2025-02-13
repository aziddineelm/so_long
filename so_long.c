/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-mans <ael-mans@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 17:52:55 by ael-mans          #+#    #+#             */
/*   Updated: 2025/02/13 18:00:09 by ael-mans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

void	print_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		printf("%s", map[i]);
		i++;
	}
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ac == 2)
	{
		data.line = av[1];
		if (!name_check(data.line))
			return (ft_putstr("Error!\nPlease Entre a valid map\n"), 1);
		data.map_win = read_map(data.line, &data.rows);
		if (!data.map_win)
			return (0);
		print_map(data.map_win);
		data.mlx = mlx_init();
		data.window = mlx_new_window(data.mlx, 740, 480, "so_long");
		mlx_key_hook(data.window, close_window, &data);
		mlx_hook(data.window, 17, 0, close_x_window, 0);
		mlx_loop(data.mlx);
	}
	return (0);
}
