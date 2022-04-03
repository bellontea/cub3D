#include "cub3d.h"

void clear_screen(t_all *vars)
{
	mlx_destroy_image(vars->win.mlx, vars->win.img->img);
	free(vars->win.img);
	vars->win.img = init_new_img(vars->win.mlx);
}

void move_p(t_all *vars)
{
	double	shift = 0.02;
	double	temp;

	vars->player.y -= vars->move.key_w * shift;
	if(vars->map[(int)vars->player.y][(int)vars->player.x] != '0')
		vars->player.y += vars->move.key_w * shift;
	vars->player.x -= vars->move.key_a * shift;
	if(vars->map[(int)vars->player.y][(int)vars->player.x] != '0')
		vars->player.x += vars->move.key_a * shift;
	vars->player.y += vars->move.key_s * shift;
	if(vars->map[(int)(vars->player.y + 0.5)][(int)(vars->player.x + 0.5)] != '0')
		vars->player.y -= vars->move.key_s * shift;
	vars->player.x += vars->move.key_d * shift;
	if(vars->map[(int)(vars->player.y + 0.5)][(int)(vars->player.x + 0.5)] != '0')
		vars->player.x -= vars->move.key_d * shift;
}

int	render(t_all *vars)
{
	clear_screen(vars);
	move_p(vars);
	// for (int i = 0; i < 10000; i++);
	for(int i = 0; i < vars->win.iter % (int)WIN_HEIGHT; i++)
		pixel_put(vars->win.img, i, 10, create_trgb(0, 255, 255, 255));
	mini_map(vars);
	refresh_win(&vars->win);
	return (0);
}