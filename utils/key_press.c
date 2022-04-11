/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjamis <tjamis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 16:30:03 by tjamis            #+#    #+#             */
/*   Updated: 2022/04/11 16:30:05 by tjamis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdio.h>

void	key_move(int key, t_all *vars)
{
	if (key == KEY_A)
		vars->move.key_a = 1;
	if (key == KEY_W)
		vars->move.key_w = 1;
	if (key == KEY_D)
		vars->move.key_d = 1;
	if (key == KEY_S)
		vars->move.key_s = 1;
	if (key == KEY_LEFT)
		vars->move.key_l = 1;
	if (key == KEY_RIGHT)
		vars->move.key_r = 1;
}

int	key_press(int key, t_all *vars)
{
	key_move(key, vars);
	if (key == KEY_ESC)
		close_win(vars);
	return (0);
}
