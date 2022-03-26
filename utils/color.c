#include "cub3d.h"

int	create_trgb(US_INT t, US_INT r, US_INT g, US_INT b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}
