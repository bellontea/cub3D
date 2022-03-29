#include "cub3d.h"

void clear_screen(t_all *vars)
{
	mlx_destroy_image(vars->win.mlx, vars->win.img->img);
	free(vars->win.img);
	vars->win.img = init_new_img(vars->win.mlx);
}


int	render(t_all *vars)
{
	clear_screen(vars);
	// for (int i = 0; i < 10000; i++);
	for(int i = 0; i < vars->win.iter % (int)WIN_HEIGHT; i++)
		pixel_put(vars->win.img, i, 10, create_trgb(0, 255, 255, 255));
	mini_map(vars, 0, 50, 15);
	refresh_win(&vars->win);
	return (0);
}