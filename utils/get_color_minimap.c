#include "cub3d.h"

int get_color_minimap(char ch)
{
	int color[] = {create_trgb(0, 0, 0, 0) , create_trgb(0, 255, 255, 255)};
	int	color_name[] = {'0', '1', 0};
	int	i;

	i = 0;
	while(color_name[i] && color_name[i] != ch)
		i++;
	if(color_name[i])
		return (color[i]);
	return (color[0]);
}