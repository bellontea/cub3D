/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_head_parcer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjamis <tjamis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 18:21:24 by tjamis            #+#    #+#             */
/*   Updated: 2022/04/11 18:21:28 by tjamis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	*init_head_parcer(t_all *vars)
{
	int	(**func)(t_all *, char *);

	func = ft_calloc(6, sizeof(void *));
	func[0] = set_ceilling_color;
	func[1] = set_floor_color;
	func[2] = set_no_texture;
	func[3] = set_so_texture;
	func[4] = set_we_texture;
	func[5] = set_ea_texture;
	vars->color_c = -1;
	vars->color_f = -1;
	return (func);
}
