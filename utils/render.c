/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mslyther <mslyther@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 16:30:23 by tjamis            #+#    #+#             */
/*   Updated: 2022/04/11 20:08:30 by mslyther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	clear_screen(t_all *vars)
{
	int	x;
	int	y;

	y = 0;
	while (y < WIN_HEIGHT)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			if (y < WIN_HEIGHT / 2)
				pixel_put(vars->win.img, x, y, vars->color_c);
			else
				pixel_put(vars->win.img, x, y, vars->color_f);
			x++;
		}
		y++;
	}
}

int	collision(t_all *vars, float _x, float _y)
{
	float	x;
	float	y;
	float	size_c;

	size_c = 0.2;
	y = -size_c;
	while (y < size_c + 0.1)
	{
		x = -size_c;
		while (x < size_c + 0.1)
		{
			if (vars->map[(int)(vars->player.pos.y + _y + y)][(int)
				(vars->player.pos.x + _x + x)] != '0')
				return (1);
			x += size_c;
		}
		y += size_c;
	}
	return (0);
}

void	change_angle(t_all *vars)
{
	if (vars->move.key_r)
	{
		vars->player.angle -= 0.05;
		while (vars->player.angle < 0)
			vars->player.angle += 2 * PI;
	}
	if (vars->move.key_l)
	{
		vars->player.angle += 0.05;
		if (vars->player.angle > (2 * PI))
			vars->player.angle -= 2 * PI;
	}
}

void	move_p(t_all *vars)
{
	double	temp;
	double	delt_x;
	double	delt_y;

	delt_x = cos(vars->player.angle) * 0.1;
	delt_y = sin(vars->player.angle) * 0.1;
	init_player(vars);
	if (!collision(vars, delt_x * vars->move.key_w, 0))
		vars->player.pos.x += delt_x * vars->move.key_w;
	if (!collision(vars, 0, delt_y * vars->move.key_w))
		vars->player.pos.y += delt_y * vars->move.key_w;
	if (!collision(vars, -delt_x * vars->move.key_s, 0))
		vars->player.pos.x -= delt_x * vars->move.key_s;
	if (!collision(vars, 0, -delt_y * vars->move.key_s))
		vars->player.pos.y -= delt_y * vars->move.key_s;
	delt_x = cos(vars->player.angle - (PI / 2)) * 0.1;
	delt_y = sin(vars->player.angle - (PI / 2)) * 0.1;
	if (!collision(vars, delt_x * vars->move.key_d, 0))
		vars->player.pos.x += delt_x * vars->move.key_d;
	if (!collision(vars, 0, delt_y * vars->move.key_d))
		vars->player.pos.y += delt_y * vars->move.key_d;
	if (!collision(vars, -delt_x * vars->move.key_a, 0))
		vars->player.pos.x -= delt_x * vars->move.key_a;
	if (!collision(vars, 0, -delt_y * vars->move.key_a))
		vars->player.pos.y -= delt_y * vars->move.key_a;
}

int	render(t_all *vars)
{
	clear_screen(vars);
	change_angle(vars);
	move_p(vars);
	raycaster(vars);
	mini_map(vars);
	refresh_win(&vars->win);
	return (0);
}
