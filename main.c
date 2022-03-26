#include "cub3d.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_vars vars;

	ft_bzero(&vars, sizeof(t_vars));
	if(!init_mlx(&vars, argc, argv))
		mlx_loop(vars.mlx);	
}