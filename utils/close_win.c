/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_win.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjamis <tjamis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 16:29:31 by tjamis            #+#    #+#             */
/*   Updated: 2022/04/11 16:29:32 by tjamis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdio.h>

void	free_dauble_arr(int **arr, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	ft_free_array(char **array)
{
	int	i;

	i = 0;
	if (!array)
		return ;
	while (array[i])
	{
		if (array[i])
			free(array[i]);
		i++;
	}
	free(array);
}

int	close_win(t_all *vars)
{
	int	i;

	if (vars->win.img)
		mlx_destroy_image(vars->win.mlx, vars->win.img->img);
	if (vars->win.win)
		mlx_destroy_window(vars->win.mlx, vars->win.win);
	if (vars->win.mlx)
		mlx_destroy_display(vars->win.mlx);
	if (vars->win.mlx)
		free(vars->win.mlx);
	if (vars->win.img)
		free(vars->win.img);
	i = 0;
	while (i < 4)
	{
		if (vars->texture[i].pic)
			free_dauble_arr(vars->texture[i].pic, vars->texture[i].height);
		i++;
	}
	ft_free_array(vars->map);
	exit(0);
}
