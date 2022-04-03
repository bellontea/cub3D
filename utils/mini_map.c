#include "cub3d.h"

int get_color_minimap(char ch)
{
	int color[] = {create_trgb(0, 0, 0, 0) , create_trgb(0, 255, 255, 255)};
	int	color_name[] = {'0', '1', 0};
	int	i;

	i = 0;
	while(color_name[i] && color_name[i] != ch)
		i++;
	if(color_name[i])
		return (color[i]);
	return (color[0]);
}

int max_len(char **map)
{
	int	max;
	int	lenght;
	int	i;

	max = ft_strlen(map[0]);
	i = 1;
	while(map && map[i])
	{
		lenght = ft_strlen(map[i]);
		if(lenght > max)
			max = lenght;
		i++;
	}
	i++;
	if(i > max)
		max = i;
	return (max - 1);
}

void drow_sqr(t_point point, int color, t_image *img)
{
	int	i;
	int	j;

	i = 0;
	while (i < point.z)
	{
		j = 0;
		while (j < point.z)
		{
			pixel_put(img, point.x + i, point.y + j, color);
			j++;
		}
		i++;
	}
}

void drow_line(t_point point, char *line, int size, t_image *img)
{
	int i;

	i = 0;
	while(line[i] && point.x < size)
	{
		drow_sqr(point, get_color_minimap(line[i]), img);
		point.x += point.z;
		i++;
	}
}

void set_player(t_point point, t_all * vars, int size)
{
	float	temp;

	point.x += modff(vars->player.x, &temp) * point.z;
	point.x += temp * point.z;
	point.y += modff(vars->player.y, &temp) * point.z;
	point.y += temp * point.z;
	point.z = size / 2;
	drow_sqr(point, create_trgb(0, 250, 0 , 0), vars->win.img);
}

void mini_map(t_all *vars)
{
	int	size = WIN_HEIGHT * 0.3;
	t_point		point;
	int			i;

	point.x = 0;
	point.z = size / max_len(vars->map);
	size = point.z * max_len(vars->map);
	point.y = WIN_HEIGHT - size;
	i = 0;
	while(vars->map[i] && point.y < size + WIN_HEIGHT)
	{
		drow_line(point, vars->map[i], size, vars->win.img);
		point.y += point.z;
		i++;
	}
	i = -1;
	point.y = WIN_HEIGHT - size;
	set_player(point, vars, point.z);
	point.z = 5;
	while (i * point.z < size)
	{
		point.y = WIN_HEIGHT - size + i * point.z;
		point.x = size;
		drow_sqr(point, create_trgb(0, 250, 110 , 5), vars->win.img);
		point.y = WIN_HEIGHT - size - point.z;
		point.x = i * point.z;
		drow_sqr(point, create_trgb(0, 250, 110 , 5), vars->win.img);
		i++;
	}
}