/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjamis <tjamis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 16:29:25 by tjamis            #+#    #+#             */
/*   Updated: 2022/04/11 18:23:13 by tjamis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_space(char **map, int x, int y)
{
	int	i;
	int	j;

	if (map[y][x] != '0')
		return (0);
	if (x == 0 || y == 0 || !map[y + 1])
		return (map[y][x] == '0');
	i = -1;
	while (i <= 1)
	{
		j = -1;
		while (j <= 1)
		{
			if (y != 0 && x != 0 && !(ft_strlen(map[y + i]) < x + j
					|| map[y + i][x + j] == '0' || map[y + i][x + j] == '1'))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_edge(char *map)
{
	int	x;

	x = 0;
	while (map[x])
	{
		if (!(map[x] == ' ' || map[x] == '1' || map[x] == '\n'))
			return (1);
		x++;
	}
	return (0);
}

int	check_map(char **map)
{
	int	y;
	int	x;

	y = 0;
	while (map[y])
	{
		x = 0;
		if (map[y][x] != '1' && map[y][x] != ' ' && map[y][x] != '\n')
			return (1);
		while (map[y][x])
		{
			if (check_space(map, x, y))
				return (1);
			x++;
		}
		y++;
	}
	y--;
	return (check_edge(map[0]) || check_edge(map[y]));
}
