#include "so_long.h"
#include <fcntl.h>
#include <mlx.h>
#include <stdio.h>

int	main(int ac, char **av)
{
	char	*map;
	char	**map_win;

	int i = 0;

	if (ac == 2)
	{
		map = av[1];
		t_data	vars;
		if (name_check(map))
		{
			printf("Error\nMap file extension is not .ber\n");
			exit(1);
		}
		map_win = read_map(map);
		while (map_win)
		{
			printf("%s", map_win[i]);
			i++;
		}
		vars.mlx = mlx_init();
		vars.window = mlx_new_window(vars.mlx, 740, 480, "so_long");
		mlx_key_hook(vars.window, close_window, &vars);
		mlx_hook(vars.window, 17, 0, close_x_window, 0);
		mlx_loop(vars.mlx);
	}
	return (0);
}
