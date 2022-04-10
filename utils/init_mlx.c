#include "cub3d.h"

int	init_mlx(t_all *vars, int argc, char **argv)
{
	vars->win.mlx = mlx_init();
	if (vars->win.mlx == NULL)
		return (1);
	vars->win.win = mlx_new_window(vars->win.mlx, WIN_WIDTH, WIN_HEIGHT,
			"cub3d");
	vars->win.img = init_new_img(vars->win.mlx);
	mlx_hook(vars->win.win, 2, 1L << 0, key_press, vars);
	mlx_hook(vars->win.win, 3, 1L << 1, key_realease, vars);
	mlx_hook(vars->win.win, 17, 0, close_win, vars);
	mlx_loop_hook(vars->win.mlx, render, vars);
	vars->win.width = WIN_WIDTH;
	vars->win.height = WIN_HEIGHT;
	return (0);
}
