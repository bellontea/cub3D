/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color_minimap.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjamis <tjamis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 16:29:44 by tjamis            #+#    #+#             */
/*   Updated: 2022/04/11 16:29:45 by tjamis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	get_color_minimap(char ch)
{
	const int	color[]
		= {create_trgb(0, 0, 0, 0), create_trgb(0, 255, 255, 255)};
	const int	color_name[] = {'0', '1', 0};
	int			i;

	i = 0;
	while (color_name[i] && color_name[i] != ch)
		i++;
	if (color_name[i])
		return (color[i]);
	return (-1);
}
