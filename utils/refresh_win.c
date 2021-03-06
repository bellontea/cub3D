/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refresh_win.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjamis <tjamis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 16:30:20 by tjamis            #+#    #+#             */
/*   Updated: 2022/04/11 16:30:21 by tjamis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	refresh_win(t_win *win)
{
	char	*str;

	win->iter++;
	mlx_put_image_to_window(win->mlx, win->win, win->img->img, 0, 0);
	str = ft_itoa(win->iter);
	mlx_string_put(win->mlx, win->win, 1, 10,
		create_trgb(0, 225, 225, 225), str);
	free(str);
}
