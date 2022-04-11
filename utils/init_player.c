/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjamis <tjamis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 16:29:57 by tjamis            #+#    #+#             */
/*   Updated: 2022/04/11 17:31:06 by tjamis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	init_player(t_all *vars)
{
	vars->player.plane.x = cos(vars->player.angle - (PI / 2)) * 0.66;
	vars->player.plane.y = sin(vars->player.angle - (PI / 2)) * 0.66;
	vars->player.dir.x = cos(vars->player.angle);
	vars->player.dir.y = sin(vars->player.angle);
	return (0);
}

int	set_player(t_all *vars, int y)
{
	int			i;
	char		*str;
	const char	*directions = "ENWS";
	char		*temp;

	str = vars->map[y];
	if (!str)
		return (0);
	i = 0;
	while (str[i])
	{
		temp = ft_strchr(directions, str[i]);
		if (temp)
		{
			if (vars->player.pos.y != 0)
				return (1);
			vars->player.pos.y = y + 0.5;
			vars->player.pos.x = i + 0.5;
			vars->player.angle = (temp - directions) * (PI / 2);
			str[i] = '0';
		}
		i++;
	}
	return (0);
}
