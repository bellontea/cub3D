/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjamis <tjamis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 16:30:25 by tjamis            #+#    #+#             */
/*   Updated: 2022/04/11 19:39:21 by tjamis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	set_texture(t_all *vars, t_texture *texture)
{
	int		i;
	int		j;
	t_image	img;

	img.img = mlx_xpm_file_to_image(vars->win.mlx, texture->file_name,
			&texture->width, &texture->height);
	if (texture->pic || !img.img || texture->height != texture->width)
		return (1);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	texture->pic = ft_calloc(texture->height, sizeof(int *));
	i = 0;
	while (i < texture->height)
	{
		texture->pic[i] = ft_calloc(texture->height, sizeof(int));
		j = 0;
		while (j < texture->width)
		{
			texture->pic[i][j] = *(unsigned int *)get_x_y(&img, i, j);
			j++;
		}
		i++;
	}
	mlx_destroy_image(vars->win.mlx, img.img);
	return (0);
}

int	set_no_texture(t_all *vars, char *str)
{
	int	i;

	while (ft_isspace(*str))
		str++;
	i = ft_strlen(str) - 1;
	while (ft_isspace(str[i]))
		i--;
	str[i + 1] = 0;
	vars->texture[0].file_name = str;
	return (set_texture(vars, vars->texture));
}

int	set_so_texture(t_all *vars, char *str)
{
	int	i;

	while (ft_isspace(*str))
		str++;
	i = ft_strlen(str) - 1;
	while (ft_isspace(str[i]))
		i--;
	str[i + 1] = 0;
	vars->texture[1].file_name = str;
	return (set_texture(vars, vars->texture + 1));
}

int	set_we_texture(t_all *vars, char *str)
{
	int	i;

	while (ft_isspace(*str))
		str++;
	i = ft_strlen(str) - 1;
	while (ft_isspace(str[i]))
		i--;
	str[i + 1] = 0;
	vars->texture[2].file_name = str;
	return (set_texture(vars, vars->texture + 2));
}

int	set_ea_texture(t_all *vars, char *str)
{
	int	i;

	while (ft_isspace(*str))
		str++;
	i = ft_strlen(str) - 1;
	while (ft_isspace(str[i]))
		i--;
	str[i + 1] = 0;
	vars->texture[3].file_name = str;
	return (set_texture(vars, vars->texture + 3));
}
