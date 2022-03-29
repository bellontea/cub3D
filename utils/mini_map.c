#include "cub3d.h"

int get_color_minimap(char index)
{
	int color[] = {create_trgb(0, 0, 0, 0) , create_trgb(0, 255, 255, 255)};

	if(index == ' ' || index == '\n' || index - '0' > 2)
		return color[0];
	return color[index - '0'];
}

void drow_sqr(int x, int y, int size, int color, t_image *img)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			pixel_put(img, x + i, y + j, color);
			j++;
		}
		i++;
	}
}

void mini_map(t_all *vars, int x, int y, int size)
{
	int i;
	int	j;

	if(!vars->map)
		return ;
	i = 0;
	while (vars->map[i])
	{
		j = 0;
		while(vars->map[i][j])
		{
			drow_sqr((x + j * size), (y + i * size), size, get_color_minimap(vars->map[i][j]), vars->win.img);
			j++;
		}
		i++;
	}
}
