#include "cub3d.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_all vars;

	ft_bzero(&vars, sizeof(t_all));
	if(!init_mlx(&vars.win, argc, argv))
		mlx_loop(vars.win.mlx);	
}