#include "cub3d.h"

int init_player(t_all *vars)
{
	vars->player.plane.x = 0;
	vars->player.plane.y = 0.66;
	vars->player.dir.x = cos(vars->player.angle);
	vars->player.dir.y = sin(vars->player.angle);
	return 0;
}