#include "cub3d.h"

void draw_vision(t_point point, t_all * vars)
{
	t_point end; 
	float	temp;
	int		i;

	i = 0;
	while (vars->map[i])
	{
		point.y += point.z;
		i++;
	}
	point.y -= point.z;
	point.x += modff(vars->player.pos.x , &temp) * point.z;
	point.x += temp * point.z;
	point.y -= modff(vars->player.pos.y - 1, &temp) * point.z;
	point.y -= temp * point.z;

	end.x = -cos(vars->player.angle + PI) * point.z * 1.5 + point.x;
	end.y = sin(vars->player.angle + PI) * point.z * 1.5 + point.y;
	point.z /= 5;
	DDA(point, end, point.z, vars);
}

void draw_player(t_point point, t_all * vars)
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
	point.x += modff(vars->player.pos.x - 0.15 , &temp) * point.z;
	point.x += temp * point.z;
	point.y -= modff(vars->player.pos.y - 0.7, &temp) * point.z;
	point.y -= temp * point.z;
	point.z /= 2;
	drow_sqr(point, create_trgb(0, 250, 0 , 0), vars->win.img);
}

void draw_minimap(t_point point, t_all * vars)
{
	int		i;
	int		j;
	t_point drow;

	drow = point;
	i = 0;
	while(vars->map[i])
		i++;
	i--;
	while(i >= 0)
	{
		drow.x = point.x;
		j = 0;
		while(vars->map[i][j + 1])
		{
			drow_sqr(drow, get_color_minimap(vars->map[i][j]), vars->win.img);
			drow.x += point.z;
			j++;
		}
		drow.y += point.z;
		i--;
	}
}