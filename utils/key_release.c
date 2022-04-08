#include "cub3d.h"
#include <stdio.h>

void	key_move_r(int key, t_all *vars)
{
	if(key == KEY_A)
		vars->move.key_a = 0;
	if(key == KEY_W)
		vars->move.key_w = 0;
	if(key == KEY_D)
		vars->move.key_d = 0;
	if(key == KEY_S)
		vars->move.key_s = 0;
	if(key == KEY_LEFT)
		vars->move.key_l = 0;
	if(key == KEY_RIGHT)
		vars->move.key_r = 0;

}

int	key_realease(int key, t_all *vars)
{
	key_move_r(key, vars);
	return (0);
}
