#include "cub3d.h"

int set_clolor(t_all *vars, char *str)
{
	int	i;
	int	count;
	int	color[3];

	count = 0;
	i = 0;
	while(count < 3)
	{
		while(str[i] && ft_isspace(str[i]))
			i++;
		if (!str[i] || !ft_isdigit(str[i]))
			return 1;
		color[count] = ft_atoi(str + i);
		count++;
		while(str[i] && ft_isdigit(str[i]))
			i++;
		if (str[i] == ',')
			i++;
	}
	if (count == 3)
		return (create_trgb(0, color[0], color[1], color[2]));
	return -1;
}

int set_floor_color(t_all *vars, char *str)
{
	if (vars->color_f != -1)
		return (1);
	vars->color_f = set_clolor(vars, str);
	if (vars->color_c == -1)
		return (1);
	return (0);
}

int set_ceilling_color(t_all *vars, char *str)
{
	if (vars->color_c != -1)
		return (1);
	vars->color_c = set_clolor(vars, str);
	if (vars->color_c == -1)
		return (1);
	return (0);
}

int head_parcer(t_all *vars, int file)
{
	char		*str;
	const char	*identifier[] = {"C", "F", "NO", "SO", "WE", "EA", NULL};
	int			(*func[])(t_all *, char *) = {set_ceilling_color, set_floor_color};
	int			count;
	int			i;

	vars->color_c = -1;
	vars->color_f = -1;
	count = 0;
	str = get_next_line(file);
	while (count < 2 && str)
	{
		i = 0;
		while (identifier[i])
		{
			if(!ft_strncmp(identifier[i], str, ft_strlen(identifier[i])))
			{
				if(func[i](vars, str + ft_strlen(identifier[i])))
				{
					printf("error header\n");
					return (1);
				}
				count++;
				break;
			}
			i++;
		}
		free(str);
		str = get_next_line(file);
	}
	return (count != 2);
}