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
			if (vars->map[(int)(vars->player.pos.y + y)][(int)(vars->player.pos.x + x)] != '0')
				return (1);
			x += size_c;
		}
		y += size_c;
	}
	return (0);
}

void	change_angle(t_all *vars)
{
	if(vars->move.key_l)
	{
		vars->player.angle -= 0.05;
		while(vars->player.angle < 0)
			vars->player.angle += 2 *PI;
	}
	if(vars->move.key_r)
	{
		vars->player.angle += 0.05;
		if(vars->player.angle > (2 * PI))
			vars->player.angle -= 2 * PI;
	}
}

void move_p(t_all *vars)
{
	double	temp;
	double	deltX;
	double	deltY;
	
	change_angle(vars);
	deltX = cos(vars->player.angle) * 0.1;
	deltY = sin(vars->player.angle) * 0.1;
	
	vars->player.pos.x += deltX * vars->move.key_w;
	vars->player.pos.y += deltY * vars->move.key_w;

	vars->player.pos.x -= deltX * vars->move.key_s;
	vars->player.pos.y -= deltY * vars->move.key_s;
}

int	render(t_all *vars)
{
	clear_screen(vars);
	move_p(vars);
	raycaster(vars);
	// for (int i = 0; i < 10000; i++);
	for(int i = 0; i < vars->win.iter % (int)WIN_HEIGHT; i++)
		pixel_put(vars->win.img, i, 10, create_trgb(0, 255, 255, 255));
	mini_map(vars);
	refresh_win(&vars->win);
	return (0);
}