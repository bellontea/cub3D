#include "cub3d.h"

void	pixel_put(t_image *data, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || y < 0
		|| x >= WIN_HEIGHT || y >= WIN_WIDTH)
		return ;
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}