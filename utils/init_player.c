#include "cub3d.h"

int init_player(t_all *vars)
{
	vars->player.plane.x = cos(vars->player.angle - (PI / 2)) * 0.66;
	vars->player.plane.y = sin(vars->player.angle - (PI / 2)) * 0.66;
	vars->player.dir.x = cos(vars->player.angle);
	vars->player.dir.y = sin(vars->player.angle);
	return 0;
}