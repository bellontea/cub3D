#include "cub3d.h"

void	refresh_win(t_vars *vars)
{
	char	*str;

	vars->iter++;
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img->img, 0, 0);
	str = ft_itoa(vars->iter);
	mlx_string_put(vars->mlx, vars->win, 1, 10,
		create_trgb(0, 225, 225, 225), str);
	free(str);
}