#include "cub3d.h"

void clear_screen(t_all *vars)
{
	int	x;
	int	y;

	y = 0;
	while(y < WIN_HEIGHT)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			if (y < WIN_HEIGHT / 2)
				pixel_put(vars->win.img, x, y, vars->color_c);
			else
				pixel_put(vars->win.img, x, y, vars->color_f);
			x++;
		}
		y++;
	}
}

int collision(t_all *vars, float _x, float _y)
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
			if (vars->map[(int)(vars->player.pos.y + _y + y)][(int)(vars->player.pos.x + _x + x)] != '0')
				return (1);
			x += size_c;
		}
		y += size_c;
	}
	return (0);
}

void	change_angle(t_all *vars)
{
	if(vars->move.key_r)
	{
		vars->player.angle -= 0.05;
		while(vars->player.angle < 0)
			vars->player.angle += 2 *PI;
	}
	if(vars->move.key_l)
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
	init_player(vars);
	if(!collision(vars, deltX * vars->move.key_w, 0))
		vars->player.pos.x += deltX * vars->move.key_w;
	if(!collision(vars, 0, deltY * vars->move.key_w))
		vars->player.pos.y += deltY * vars->move.key_w;
	if(!collision(vars, -deltX * vars->move.key_s, 0))
		vars->player.pos.x -= deltX * vars->move.key_s;
	if(!collision(vars, 0, -deltY * vars->move.key_s))
		vars->player.pos.y -= deltY * vars->move.key_s;
	deltX = cos(vars->player.angle - (PI / 2)) * 0.1;
	deltY = sin(vars->player.angle - (PI / 2)) * 0.1;
	if(!collision(vars, deltX * vars->move.key_d, 0))
		vars->player.pos.x += deltX * vars->move.key_d;
	if(!collision(vars, 0, deltY * vars->move.key_d))
		vars->player.pos.y += deltY * vars->move.key_d;
	if(!collision(vars, -deltX * vars->move.key_a, 0))
		vars->player.pos.x -= deltX * vars->move.key_a;
	if(!collision(vars, 0, -deltY * vars->move.key_a))
		vars->player.pos.y -= deltY * vars->move.key_a;
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