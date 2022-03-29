#include "cub3d.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_all vars;

	if(argc < 2)
		return(1);
	ft_bzero(&vars, sizeof(t_all));
	if(!init_mlx(&vars.win, argc, argv) && !set_map(&vars, argv[1]))
		mlx_loop(vars.win.mlx);	
}