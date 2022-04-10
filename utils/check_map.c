#include "cub3d.h"

int	check_space(char **map, int x, int y)
{
	int	i;
	int	j;

	if (!(map[y][x] == ' ' || map[y][x] == '\n'))
		return (0);
	i = -1;
	while (i <= 1)
	{
		j = -1;
		while (j <= 1)
		{
			if (x + j >= 0 && y + i >= 0
				&& map[y + i]
				&& ft_strlen(map[y + i]) > x + j
				&& !(map[y + i][x + j] == ' '
				|| map[y + i][x + j] == '1'
				|| map[y + i][x + j] == '\n'))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_edge(char *map)
{
	int	x;

	x = 0;
	while (map[x])
	{
		if (!(map[x] == ' ' || map[x] == '1' || map[x] == '\n'))
			return (1);
		x++;
	}
	return (0);
}

int	check_map(char **map)
{
	int	y;
	int	x;

	y = 0;
	while (map[y])
	{
		x = 0;
		if (map[y][x] != '1' && map[y][x] != ' ' && map[y][x] != '\n')
			return (1);
		while (map[y][x])
		{
			if (check_space(map, x, y))
				return (1);
			x++;
		}
		y++;
	}
	y--;
	return (check_edge(map[0]) || check_edge(map[y]));
}
