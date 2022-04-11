/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjamis <tjamis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 20:46:50 by tjamis            #+#    #+#             */
/*   Updated: 2022/04/11 20:47:12 by tjamis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	get_color(char *str, int *i, int count, int *color)
{
	while (str[*i] && ft_isspace(str[*i]))
		(*i)++;
	if (!str[*i] || !ft_isdigit(str[*i]))
		return (-1);
	color[count] = ft_atoi(str + *i);
	if (color[count] >= 255 || color[count] < 0)
		return (-1);
	return (0);
}

int	set_color( char *str)
{
	int	i;
	int	count;
	int	color[3];

	count = 0;
	i = 0;
	while (count < 3)
	{
		if (get_color(str, &i, count, color))
			return (-1);
		count++;
		while (str[i] && ft_isdigit(str[i]))
			i++;
		while (str[i] && ft_isspace(str[i]))
			i++;
		if (str[i] && str[i] == ',')
			i++;
		else if (count < 3)
			return (-1);
	}
	while (str[i] && ft_isspace(str[i]))
		i++;
	if (count == 3 && !str[i])
		return (create_trgb(0, color[0], color[1], color[2]));
	return (-1);
}

int	set_floor_color(t_all *vars, char *str)
{
	if (vars->color_f != -1)
		return (1);
	vars->color_f = set_color(str);
	if (vars->color_f == -1)
		return (1);
	return (0);
}

int	set_ceilling_color(t_all *vars, char *str)
{
	if (vars->color_c != -1)
		return (1);
	vars->color_c = set_color(str);
	if (vars->color_c == -1)
		return (1);
	return (0);
}
