/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   name_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-mans <ael-mans@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 20:37:18 by ael-mans          #+#    #+#             */
/*   Updated: 2025/02/10 21:22:41 by ael-mans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	name_check(char *map)
{
	size_t	len;

	len = ft_strlen(map);
	if (len < 5 || ft_strcmp(map + len - 4, ".ber") != 0)
		return (1);
	return (0);
}

int	check_map(char *map)
{
	if (name_check(map))
		return (1);
	
	return (0);
}
char	read_map(char *map)
{
	char	*line;


}
