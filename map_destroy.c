/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_destroy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-mans <ael-mans@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 10:49:45 by ael-mans          #+#    #+#             */
/*   Updated: 2025/02/11 10:49:58 by ael-mans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_window(int keycode, t_data *vars)
{
	if (keycode == 65307)
	{
		mlx_destroy_window(vars->mlx, vars->window);
		exit(1);
	}
	return (0);
}

int	close_x_window(void *ptr)
{
	(void)ptr;
	exit(1);
}
