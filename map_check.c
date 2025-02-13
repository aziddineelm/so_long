/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-mans <ael-mans@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 20:37:18 by ael-mans          #+#    #+#             */
/*   Updated: 2025/02/13 18:00:54 by ael-mans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	name_check(char *map)
{
	size_t	len;

	len = ft_strlen(map);
	if (ft_strcmp(map + len - 4, ".ber") != 0)
		return (0);
	if (len < 5)
	{
		ft_putstr("Error!\nPlease Enter at least 1 character with \".ber\"");
		exit(0);
	}
	return (1);
}
