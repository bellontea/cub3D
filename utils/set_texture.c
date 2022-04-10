#include "cub3d.h"

int	set_texture(t_all *vars, t_texture *texture)
{
	int		i;
	int		j;
	t_image	img;

	img.img = mlx_xpm_file_to_image(vars->win.mlx, texture->file_name,
			&texture->width, &texture->height);
	if (texture->pic || !img.img)
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

int	set_NO_texture(t_all *vars, char *str)
{
	while (ft_isspace(*str))
		str++;
	str[ft_strlen(str) - 1] = 0;
	vars->texture[0].file_name = str;
	return (set_texture(vars, vars->texture));
}

int	set_SO_texture(t_all *vars, char *str)
{
	while (ft_isspace(*str))
		str++;
	str[ft_strlen(str) - 1] = 0;
	vars->texture[1].file_name = str;
	return (set_texture(vars, vars->texture + 1));
}

int	set_WE_texture(t_all *vars, char *str)
{
	while (ft_isspace(*str))
		str++;
	str[ft_strlen(str) - 1] = 0;
	vars->texture[2].file_name = str;
	return (set_texture(vars, vars->texture + 2));
}

int	set_EA_texture(t_all *vars, char *str)
{
	while (ft_isspace(*str))
		str++;
	str[ft_strlen(str) - 1] = 0;
	vars->texture[3].file_name = str;
	return (set_texture(vars, vars->texture + 3));
}
