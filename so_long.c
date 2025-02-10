#include "so_long.h"
#include <fcntl.h>
#include <stdio.h>

int	close_window(int keycode, t_data *vars)
{
	if (keycode == 65307)
	{
		mlx_destroy_window(vars->mlx, vars->window);
		exit(0);
	}
	return (0);
}

int	check_map(char *map)
{
	char	*line;
	int		fd;

	fd = open("map", O_RDONLY);
	line = get_next_line(fd);
	while (get_next_line(fd))
	{
		if (line == NULL)
		{
			perror("Error\nMap is empty\n");
			exit(1);
		}
	}
	line = get_next_line(fd);
	close(fd);
	return (0);
}

void	load_map(char *map)
{
	t_data	vars;

	if (!check_map(map))
	{
		perror("Error\nMap not found\n");
		exit(1);
	}
	vars.mlx = mlx_init();
	vars.window = mlx_new_window(vars.mlx, 740, 480, "so_long");
	mlx_key_hook(vars.window, close_window, &vars);
	mlx_loop(vars.mlx);
}

int	main(int ac, char **map)
{
	if (ac == 2)
	{
		load_map(map[1]);
	}
	return (0);
}
