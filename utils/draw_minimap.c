/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjamis <tjamis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 16:29:39 by tjamis            #+#    #+#             */
/*   Updated: 2022/04/11 20:16:21 by tjamis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_point	count_end(t_player plr, t_point point)
{
	double	delta;
	t_point	end;

	if (plr.side == Y_SIDE)
	{
		delta = plr.pos.x + plr.plane_wall_dist * plr.ray_dir.x;
		if (plr.curr_ray_on_map.y < plr.pos.y)
			plr.curr_ray_on_map.y++;
		end.x = point.x + delta * point.z;
		end.y = point.y - (plr.curr_ray_on_map.y - 1) * point.z;
	}
	else
	{
		delta = plr.pos.y + plr.plane_wall_dist * plr.ray_dir.y;
		if (plr.curr_ray_on_map.x < plr.pos.x)
			plr.curr_ray_on_map.x++;
		end.x = point.x + plr.curr_ray_on_map.x * point.z;
		end.y = point.y - (delta - 1) * point.z;
	}
	return (end);
}

void	draw_vision(t_point point, t_all *vars)
{
	t_point	start;
	t_point	end;
	int		i;

	i = 0;
	while (vars->map[i])
	{
		point.y += point.z;
		i++;
	}
	point.y -= point.z;
	start.x = point.x + vars->player.pos.x * point.z;
	start.y = point.y - (vars->player.pos.y - 1) * point.z;
	i = 0;
	while (i < WIN_WIDTH)
	{
		init_ray_vars(&(vars->player), i);
		ray_dda(vars);
		end = count_end(vars->player, point);
		dda(start, end, point.z / 5, vars);
		i += 10;
	}
}

void	draw_player(t_point point, t_all *vars)
{
	int		i;

	i = 0;
	while (vars->map[i])
	{
		point.y += point.z;
		i++;
	}
	point.y -= point.z;
	point.x += (vars->player.pos.x - 0.15) * point.z;
	point.y -= (vars->player.pos.y - 0.7) * point.z;
	point.z /= 2;
	drow_sqr(point, create_trgb(0, 138, 43, 226), vars->win.img);
}

void	draw_minimap(t_point point, t_all *vars)
{
	int		i;
	int		j;
	t_point	drow;
	int		color;

	drow = point;
	i = 0;
	while (vars->map[i])
		i++;
	i--;
	while (i >= 0)
	{
		drow.x = point.x;
		j = 0;
		while (vars->map[i][j])
		{
			color = get_color_minimap(vars->map[i][j]);
			if (color != -1)
				drow_sqr(drow, color, vars->win.img);
			drow.x += point.z;
			j++;
		}
		drow.y += point.z;
		i--;
	}
}
