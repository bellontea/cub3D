#include "cub3d.h"

void add_space(char **str)
{
	int		i;
	char	*tmp;

	if(!str[0])
		return ;
	tmp = ft_strchr(str[0], '\t');
	while(tmp)
	{
		i = ft_strlen(str[0]);
		str[0] = ft_realloc(str[0], i, i + 4);
		tmp = ft_strchr(str[0], '\t');
		i += 3;
		while(&str[0][i - 3] != tmp)
		{
			str[0][i] = str[0][i - 3];
			i--;
		}
		while(&str[0][i] != tmp)
		{
			str[0][i] = ' ';
			i--;
		}
		str[0][i] = ' ';
		tmp = ft_strchr(str[0], '\t');
	}
}

int check_space(char **map, int x, int y)
{
	int	i;
	int	j;

	if(!(map[y][x] == ' ' || map[y][x] == '\n'))
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

int check_map(char **map)
{
	int	y;
	int	x;

	y = 0;
	while (map[y])
	{
		x = 0;
		while(map[y][x])
		{
			if (check_space(map, x, y))
				return (1);
			x++;
		}
		y++;
	}
	y--;
	x = 0;
	while(map[y][x])
	{
		if(!(map[y][x] == ' ' || map[y][x] == '1' || map[y][x] == '\n'))
			return(1);
		x++;
	}
	return (0);
}

int set_map(t_all *vars, char *file_name)
{
	int	file;
	int	i;

	file = open(file_name, O_RDONLY);
	if (file == -1)
		return (1);
	i = 0;
	do
	{
		vars->map = ft_realloc(vars->map, i * sizeof(char *),
			(i + 1) * sizeof(char *));
		vars->map[i] = get_next_line(file);
		while (vars->map[i] && ft_strchr(vars->map[i], 'P'))
		{
			vars->player.y = i;
			vars->player.x = ft_strchr(vars->map[i], 'P') - vars->map[i];
			ft_strchr(vars->map[i], 'P')[0]= '0';
		}
		add_space(vars->map + i);
		i++;
	}while (vars->map[i - 1]);
	close(file);
	return (check_map(vars->map));
}
