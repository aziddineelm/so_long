#include "so_long.h"

int	close_window(int keycode, t_data *vars)
{
	if (keycode == 65307)
	{
		mlx_destroy_window(vars->mlx, vars->window);
		exit(0);
	}
	return (0);
}

void	load_map(void)
{
	t_data	vars;

	vars.mlx = mlx_init();
	vars.window = mlx_new_window(vars.mlx, 740, 480, "so_long");
	mlx_key_hook(vars.window, close_window, &vars);
	mlx_loop(vars.mlx);
}

int	main(int ac, char **map)
{
	if (ac == 2)
	{
		load_map();
	}
	return (0);
}
