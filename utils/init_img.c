#include "cub3d.h"

t_image	*init_new_img(void *mlx)
{
	t_image	*new_img;

	new_img = malloc(sizeof(t_image));
	if (!new_img)
		return (NULL);
	new_img->img = mlx_new_image(mlx, WIN_WIDTH, WIN_HEIGHT);
	new_img->addr = mlx_get_data_addr(new_img->img, &new_img->bits_per_pixel,
			&new_img->line_length, &new_img->endian);
	return (new_img);
}
