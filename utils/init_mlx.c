#include "cub3d.h"

int init_mlx(t_win *win, int argc, char **argv)
{
	win->mlx = mlx_init();
	if (win->mlx == NULL)
		return(1);
	win->win = mlx_new_window(win->mlx, WIN_WIDTH, WIN_HEIGHT, "cub3d");
	win->img = init_new_img(win->mlx);
	// mlx_key_hook(win->win, key_hook, win);
	// mlx_mouse_hook(win->win, mouse_hook, win);
	mlx_hook(win->win, 17, 0, close_win, win);
	mlx_loop_hook(win->mlx, render, win);
	return (0);
}