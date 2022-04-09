#include "cub3d.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_all vars;

	if(argc < 2)
		return(1);
	ft_bzero(&vars, sizeof(t_all));
	vars.player.angle = PI;
	init_player(&vars);
	if(!init_mlx(&vars, argc, argv) && !map_parcer(&vars, argv[1]))
		mlx_loop(vars.win.mlx);	
}