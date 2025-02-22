/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-mans <ael-mans@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 18:05:47 by ael-mans          #+#    #+#             */
/*   Updated: 2025/02/15 18:05:50 by ael-mans         ###   ########.fr       */
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

void	exit_error(char *msg)
{
	ft_putstr(msg);
	exit(1);
}

void	free_error(char *msg, t_data *data)
{
	if (data->map)
		free_map(data->map, data->rows);
	exit_error(msg);
}
