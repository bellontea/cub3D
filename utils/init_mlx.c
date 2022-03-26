#include "cub3d.h"

int init_mlx(t_vars *vars, int argc, char **argv)
{
	vars->mlx = mlx_init();
	if (vars->mlx == NULL)
		return(1);
	vars->win = mlx_new_window(vars->mlx, WIN_WIDTH, WIN_HEIGHT, "cub3d");
	vars->img = init_new_img(vars->mlx);
	// mlx_key_hook(vars->win, key_hook, vars);
	// mlx_mouse_hook(vars->win, mouse_hook, vars);
	mlx_hook(vars->win, 17, 0, close_win, vars);
	mlx_hook(vars->win, 10, 0, render, vars);
	return (0);
}