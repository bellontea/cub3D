/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textuting_and_drawing.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mslyther <mslyther@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 19:25:04 by mslyther          #+#    #+#             */
/*   Updated: 2022/04/11 20:10:49 by mslyther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
- Определение текстуры в зависимости от стороны света
*/
int	define_texture(t_player plr)
{
	if (plr.side == X_SIDE)
	{
		if (plr.pos.x < plr.curr_ray_on_map.x)
			return (EA);
		return (WE);
	}
	if (plr.pos.y < plr.curr_ray_on_map.y)
		return (SO);
	return (NO);
}

/*
- Вычисление расстояния x-координаты текстуры (tex_x)
*/
int	calculate_tex_x(t_player plr, t_texture tex)
{
	double	wall_x;
	int		tex_x;

	if (plr.side == X_SIDE)
		wall_x = plr.pos.y + plr.plane_wall_dist * plr.ray_dir.y;
	else
		wall_x = plr.pos.x + plr.plane_wall_dist * plr.ray_dir.x;
	wall_x -= floor((wall_x));
	tex_x = (int)(wall_x * (double)(tex.width));
	if ((plr.side == X_SIDE && plr.ray_dir.x > 0)
		|| (plr.side == Y_SIDE && plr.ray_dir.y < 0))
		tex_x = tex.width - tex_x - 1;
	return (tex_x);
}

/*
- Отрисовка вертикальной линии
*/
void	draw_ver_line(t_all *vars, int x, int tex_x, t_texture tex)
{
	double	step;
	double	tex_pos;
	int		tex_y;
	int		y;

	step = 1.0 * tex.height / vars->player.line_height;
	tex_pos = (vars->player.draw_start - WIN_HEIGHT / 2
			+ vars->player.line_height / 2) * step;
	y = vars->player.draw_start;
	while (y < vars->player.draw_end)
	{
		tex_y = (int)tex_pos & (tex.height - 1);
		tex_pos += step;
		pixel_put(vars->win.img, x, y, tex.pic[tex_x][tex_y]);
		y++;
	}
}

/*
- Вычисление высоты стены (line_height)
- Вычисление y координат для отрисовки стены (draw_start и draw_end)
*/
void	calculate_borders(t_player *plr)
{
	plr->line_height = WIN_HEIGHT / plr->plane_wall_dist;
	plr->draw_start = -(plr->line_height) / 2 + WIN_HEIGHT / 2;
	if (plr->draw_start < 0)
		plr->draw_start = 0;
	plr->draw_end = plr->line_height / 2 + WIN_HEIGHT / 2;
	if (plr->draw_end >= WIN_HEIGHT)
		plr->draw_end = WIN_HEIGHT - 1;
}
