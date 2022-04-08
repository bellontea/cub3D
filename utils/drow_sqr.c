#include "cub3d.h"

void drow_sqr(t_point point, int color, t_image *img)
{
	int	i;
	int	j;

	i = 0;
	while (i < point.z)
	{
		j = 0;
		while (j < point.z)
		{
			pixel_put(img, point.x + i, point.y + j, color);
			j++;
		}
		i++;
	}
}