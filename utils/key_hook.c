#include "cub3d.h"
#include <stdio.h>

void	key_move(int key, t_all *vars)
{
	const double	shift = 0.1;

	if (key == KEY_A || key == KEY_LEFT)
		vars->player.x -= shift;
	if (key == KEY_D || key == KEY_RIGHT)
		vars->player.x += shift;
	if (key == KEY_W || key == KEY_UP)
		vars->player.y -= shift;
	if (key == KEY_S || key == KEY_DOWN)
		vars->player.y += shift;
}

int	key_hook(int key, t_all *vars)
{
	key_move(key, vars);
	if (key == KEY_ESC)
		close_win(vars);
	return (0);
}
