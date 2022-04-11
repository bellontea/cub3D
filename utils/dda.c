#include "cub3d.h"

int	ft_max(int f, int s)
{
	if (f > s)
		return (f);
	return (s);
}

void	DDA(t_point start, t_point end, int size, t_all *vars)
{
	t_point	current;
	t_point	delta;
	t_steps	steps;
	double	x;
	double	y;
	current = start;
	current.z = size;
	x = (double)current.x;
	y = (double)current.y;
	delta.x = abs(end.x - start.x);
	delta.y = abs(end.y - start.y);
	steps.x = (double)(end.x - start.x) / (double)ft_max(delta.x, delta.y);
	steps.y = (double)(end.y - start.y) / (double)ft_max(delta.x, delta.y);
	while ((int)(end.x - x) || (int)(end.y - y))
	{
		drow_sqr(current, create_trgb(0, 238, 130, 238), vars->win.img);
		x += steps.x;
		y += steps.y;
		current.x = (int)x;
		current.y = (int)y;
		if ((start.x > WIN_WIDTH && end.x > WIN_WIDTH)
			|| (start.y > WIN_HEIGHT && end.y > WIN_HEIGHT))
			break ;
	}
}
