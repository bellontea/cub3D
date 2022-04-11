/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjamis <tjamis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 17:29:03 by tjamis            #+#    #+#             */
/*   Updated: 2022/04/11 19:23:06 by tjamis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_all	vars;

	if (argc < 2 || check_name_file(argv[1]))
	{
		printf("Error\n");
		return (1);
	}
	ft_bzero(&vars, sizeof(t_all));
	vars.player.angle = PI;
	init_player(&vars);
	if (init_mlx(&vars, argc, argv))
	{
		printf("error init\n");
		close_win(&vars);
	}
	if (map_parcer(&vars, argv[1]))
	{
		printf("error map\n");
		close_win(&vars);
	}
	mlx_loop(vars.win.mlx);
}
