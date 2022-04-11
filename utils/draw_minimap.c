#include "cub3d.h"

void	draw_vision(t_point point, t_all * vars)
{
	t_point	start;
	t_point	end;
	float	temp;
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
	int x = 0;
	double delta;
	while (x < WIN_WIDTH)
	{
		init_ray_vars(vars, x);
		rayDDA(vars);
		if (vars->player.side == Y_SIDE)
		{
			delta = vars->player.planeWallDist * vars->player.rayDir.x;
			if (vars->player.currRayOnMap.y < vars->player.pos.y)
				vars->player.currRayOnMap.y++;
			end.x = point.x + (vars->player.pos.x + delta) * point.z;
			end.y = point.y - (vars->player.currRayOnMap.y - 1) * point.z;
		}
		else
		{
			delta = vars->player.planeWallDist * vars->player.rayDir.y;
			if (vars->player.currRayOnMap.x < vars->player.pos.x)
				vars->player.currRayOnMap.x++;
			end.x = point.x + vars->player.currRayOnMap.x * point.z;
			end.y = point.y - ((vars->player.pos.y + delta) - 1) * point.z;
		}
		DDA(start, end, point.z / 5, vars);
		x += 10;
	}
	
}

void	draw_player(t_point point, t_all *vars)
{
	float	temp;
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
	drow_sqr(point, create_trgb(0, 250, 0 , 0), vars->win.img);
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
		while (vars->map[i][j + 1])
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
