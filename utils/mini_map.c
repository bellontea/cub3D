#include "cub3d.h"

int max_len(char **map)
{
	int	i;

	i = 1;
	while(map && map[i])
		i++;
	return (i);
}

void mini_map(t_all *vars)
{
	int			size;
	t_point		point;
	int			i;

	point.x = 0;
	point.z = WIN_HEIGHT * 0.3 / max_len(vars->map);
	size = point.z * max_len(vars->map);
	point.y = WIN_HEIGHT - size;
	draw_minimap(point, vars);
	draw_player(point, vars);
	draw_vision(point, vars);
	i = -1;
	point.z = 5;
	// while (i * point.z < size)
	// {
	// 	point.y = WIN_HEIGHT - size + i * point.z;
	// 	point.x = size;
	// 	drow_sqr(point, create_trgb(0, 250, 110 , 5), vars->win.img);
	// 	point.y = WIN_HEIGHT - size - point.z;
	// 	point.x = i * point.z;
	// 	drow_sqr(point, create_trgb(0, 250, 110 , 5), vars->win.img);
	// 	i++;
	// }
}