/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjamis <tjamis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 16:30:11 by tjamis            #+#    #+#             */
/*   Updated: 2022/04/11 18:35:26 by tjamis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	max_len(char **map)
{
	int	i;
	int	max;

	i = 1;
	max = 0;
	while (map && map[i])
	{
		if (max < ft_strlen(map[i]))
			max = ft_strlen(map[i]);
		i++;
	}
	if (max > i * 2)
		return (max);
	return (i);
}

void	mini_map(t_all *vars)
{
	int			size;
	t_point		point;
	int			i;

	point.x = 0;
	point.z = WIN_HEIGHT * 0.3 / max_len(vars->map);
	if (point.z < 5)
		return ;
	size = point.z * max_len(vars->map);
	point.y = WIN_HEIGHT - size;
	draw_minimap(point, vars);
	draw_player(point, vars);
	draw_vision(point, vars);
	i = -1;
	point.z = 5;
}
