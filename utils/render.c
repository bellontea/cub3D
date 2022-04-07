#include "cub3d.h"

void clear_screen(t_all *vars)
{
	mlx_destroy_image(vars->win.mlx, vars->win.img->img);
	free(vars->win.img);
	vars->win.img = init_new_img(vars->win.mlx);
}

int collision(t_all *vars)
{
	float	x;
	float	y;
	float	size_c;

	size_c = 0.2;
	y = -size_c;
	while (y < size_c + 0.1)
	{
		x = -size_c;
		while (x < size_c + 0.1)
		{
			if (vars->map[(int)(vars->player.y + y)][(int)(vars->player.x + x)] != '0')
				return (1);
			x += size_c;
		}
		y += size_c;
	}
	return (0);
}

void move_p(t_all *vars)
{
	double	shift = 0.05;
	double	temp;

	
	vars->player.y -= vars->move.key_w * shift;
	if (collision(vars))
		vars->player.y += vars->move.key_w * shift;
	vars->player.x -= vars->move.key_a * shift;
	if (collision(vars))
		vars->player.x += vars->move.key_a * shift;
	vars->player.y += vars->move.key_s * shift;
	if (collision(vars))
		vars->player.y -= vars->move.key_s * shift;
	vars->player.x += vars->move.key_d * shift;
	if (collision(vars))
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