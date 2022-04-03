#include "cub3d.h"
#include <stdio.h>

int	close_win(t_all *vars)
{
	if (vars->win.img)
		mlx_destroy_image(vars->win.mlx, vars->win.img->img);
	if (vars->win.win)
		mlx_destroy_window(vars->win.mlx, vars->win.win);
	if (vars->win.mlx)
		mlx_destroy_display(vars->win.mlx);
	if (vars->win.mlx)
		free(vars->win.mlx);
	if (vars->win.img)
		free(vars->win.img);
	exit(0);
}
