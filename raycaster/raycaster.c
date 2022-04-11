/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mslyther <mslyther@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 19:04:44 by mslyther          #+#    #+#             */
/*   Updated: 2022/04/11 20:01:05 by mslyther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
- Вычисление расстояния от начальной клетки до первых сторон x и y (side_dist)
*/
void	init_side_dist(t_player *plr)
{
	if (plr->ray_dir.x < 0)
	{
		plr->step.x = -1;
		plr->side_dist.x = (plr->pos.x - plr->curr_ray_on_map.x)
			* plr->delta_dist.x;
	}
	else
	{
		plr->step.x = 1;
		plr->side_dist.x = (plr->curr_ray_on_map.x + 1.0 - plr->pos.x)
			* plr->delta_dist.x;
	}
	if (plr->ray_dir.y < 0)
	{
		plr->step.y = -1;
		plr->side_dist.y = (plr->pos.y - plr->curr_ray_on_map.y)
			* plr->delta_dist.y;
	}
	else
	{
		plr->step.y = 1;
		plr->side_dist.y = (plr->curr_ray_on_map.y + 1.0 - plr->pos.y)
			* plr->delta_dist.y;
	}
}

/*
- Вычисление координат верктора луча (ray_dir)
- Вычисление координат клетки, в которой находится луч в 
  текущий момент (curr_ray_on_map)
- Вычичсление длины луча до следующей стороны x или y (delta_dist)
- Вычисление расстояния от начальной клетки до первых сторон x и y (side_dist)
*/
void	init_ray_vars(t_player *plr, int x)
{
	double	camera_x;

	camera_x = 2 * x / (double) WIN_WIDTH - 1;
	plr->ray_dir.x = plr->dir.x + plr->plane.x * camera_x;
	plr->ray_dir.y = plr->dir.y + plr->plane.y * camera_x;
	plr->curr_ray_on_map.x = (int) plr->pos.x;
	plr->curr_ray_on_map.y = (int) plr->pos.y;
	if (plr->ray_dir.x == 0)
		plr->delta_dist.x = 1e30;
	else
		plr->delta_dist.x = fabs(1.0 / plr->ray_dir.x);
	if (plr->ray_dir.y == 0)
		plr->delta_dist.y = 1e30;
	else
		plr->delta_dist.y = fabs(1.0 / plr->ray_dir.y);
	init_side_dist(plr);
}

/*
- DDA алгоритм: идем по лучу, пока не врежемся в стену
- Вычисление расстояния от стены до плоскости камеры (plane_wall_dist)
*/
void	ray_dda(t_all *vars)
{
	while (1)
	{
		if (vars->player.side_dist.x < vars->player.side_dist.y)
		{
			vars->player.side_dist.x += vars->player.delta_dist.x;
			vars->player.curr_ray_on_map.x += vars->player.step.x;
			vars->player.side = X_SIDE;
		}
		else
		{
			vars->player.side_dist.y += vars->player.delta_dist.y;
			vars->player.curr_ray_on_map.y += vars->player.step.y;
			vars->player.side = Y_SIDE;
		}
		if (vars->map[vars->player.curr_ray_on_map.y]
			[vars->player.curr_ray_on_map.x] == '1')
			break ;
	}
	if (vars->player.side == X_SIDE)
		vars->player.plane_wall_dist = (vars->player.side_dist.x
				- vars->player.delta_dist.x);
	else
		vars->player.plane_wall_dist = (vars->player.side_dist.y
				- vars->player.delta_dist.y);
}

void	raycaster(t_all *vars)
{
	int	x;
	int	tex_num;

	x = 0;
	while (x < WIN_WIDTH)
	{
		init_ray_vars(&(vars->player), x);
		ray_dda(vars);
		calculate_borders(&(vars->player));
		tex_num = define_texture(vars->player);
		draw_ver_line(vars, x, calculate_tex_x(vars->player,
				vars->texture[tex_num]), vars->texture[tex_num]);
		x++;
	}
}
