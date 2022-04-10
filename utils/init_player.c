#include "cub3d.h"

int	init_player(t_all *vars)
{
	vars->player.plane.x = cos(vars->player.angle - (PI / 2)) * 0.66;
	vars->player.plane.y = sin(vars->player.angle - (PI / 2)) * 0.66;
	vars->player.dir.x = cos(vars->player.angle);
	vars->player.dir.y = sin(vars->player.angle);
	return (0);
}

int	set_player(t_all *vars, int y)
{
	int			i;
	char		*str;
	const char	*directions = "ENWS";
	char		*temp;

	str = vars->map[y];
	if (!str)
		return (0);
	i = 0;
	while (str[i])
	{
		temp = ft_strchr(directions, str[i]);
		if (temp)
		{
			if (vars->player.pos.y != 0)
				return (1);
			vars->player.pos.y = y;
			vars->player.pos.x = i;
			vars->player.angle = (temp - directions) * (PI / 2);
			str[i] = '0';
		}
		i++;
	}
	return (0);
}
