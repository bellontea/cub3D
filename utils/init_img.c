#include "cub3d.h"

t_img_data *init_new_img(void *mlx)
{
	t_img_data *new_img;

	new_img = malloc(sizeof(t_img_data));
	if (!new_img)
		return (NULL);
	new_img->img = mlx_new_image(mlx, WIN_WIDTH, WIN_HEIGHT);
	new_img->addr = mlx_get_data_addr(new_img->img, &new_img->bits_per_pixel, &new_img->line_length, &new_img->endian);
	return (new_img);
}