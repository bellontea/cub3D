#include "cub3d.h"
#include <stdio.h>

void	key_move(int key, t_all *vars)
{
	if(key == KEY_A)
		vars->move.key_a = 1;
	if(key == KEY_W)
		vars->move.key_w = 1;
	if(key == KEY_D)
		vars->move.key_d = 1;
	if(key == KEY_S)
		vars->move.key_s = 1;
}

int	key_press(int key, t_all *vars)
{
	key_move(key, vars);
	if (key == KEY_ESC)
		close_win(vars);
	return (0);
}
