#include "so_long.h"
#include <mlx.h>
#include <stdlib.h>

int	close_window(int keycode, t_data *vars)
{
	if (keycode == 65307)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	return (0);
}

int	main(void)
{
	t_data	*data;

	data = (t_data *)malloc(sizeof(t_data));
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, 1920, 1080, "Hello world!");
	data->img = mlx_xpm_file_to_image(data->mlx, "./alien.xpm", &data->width,
			&data->hight);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 68, 68);
	mlx_hook(data->win, 2, 1L << 0, close_window, &data->mlx);
	mlx_loop(data->mlx);
	return (0);
}
