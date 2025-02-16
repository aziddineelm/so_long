/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-mans <ael-mans@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 20:37:18 by ael-mans          #+#    #+#             */
/*   Updated: 2025/02/15 19:28:53 by ael-mans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	name_check(char *filename)
{
	size_t	len;

	len = ft_strlen(filename);
	if (ft_strcmp(filename + len - 4, ".ber") != 0)
		return (0);
	if (len < 5)
	{
		ft_putstr("Error!\nPlease Enter at least 1 character with \".ber\"");
		exit(0);
	}
	return (1);
}

int	is_rectangle(t_data data)
{
	int	i;

	i = 0;
	while (data.map[i])
	{
		if ((ft_strlen(data.map[i]) - 1) != data.coloms)
		{
			ft_putstr("Error\nmap is not rectangle!");
			exit(1);
		}
		i++;
	}
	return (0);
}
