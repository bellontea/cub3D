#include "cub3d.h"

int	set_color(t_all *vars, char *str)
{
	int	i;
	int	count;
	int	color[3];

	count = 0;
	i = 0;
	while (count < 3)
	{
		while (str[i] && ft_isspace(str[i]))
			i++;
		if (!str[i] || !ft_isdigit(str[i]))
			return (-1);
		color[count] = ft_atoi(str + i);
		count++;
		while (str[i] && ft_isdigit(str[i]))
			i++;
		if (str[i] && str[i] == ',')
			i++;
	}
	if (count == 3)
		return (create_trgb(0, color[0], color[1], color[2]));
	return (-1);
}

int	set_floor_color(t_all *vars, char *str)
{
	if (vars->color_f != -1)
		return (1);
	vars->color_f = set_color(vars, str);
	if (vars->color_f == -1)
		return (1);
	return (0);
}

int	set_ceilling_color(t_all *vars, char *str)
{
	if (vars->color_c != -1)
		return (1);
	vars->color_c = set_color(vars, str);
	if (vars->color_c == -1)
		return (1);
	return (0);
}

void	*init_head_parcer(t_all *vars)
{
	int	(**func)(t_all *, char *);

	func = ft_calloc(6, sizeof(void *));
	func[0] = set_ceilling_color;
	func[1] = set_floor_color;
	func[2] = set_NO_texture;
	func[3] = set_SO_texture;
	func[4] = set_WE_texture;
	func[5] = set_EA_texture;
	vars->color_c = -1;
	vars->color_f = -1;
	return (func);
}

int	head_parcer(t_all *vars, int file)
{
	char		*str;
	const char	*identifier[] = {"C", "F", "NO", "SO", "WE", "EA", NULL};
	int			(**func)(t_all *, char *);
	int			count;
	int			i;

	count = 0;
	func = init_head_parcer(vars);
	str = get_next_line(file);
	while (count < 6 && str)
	{
		i = 0;
		while (identifier[i])
		{
			if (!ft_strncmp(identifier[i], str, ft_strlen(identifier[i]))
				&& !func[i](vars, str + ft_strlen(identifier[i])))
				count++;
			i++;
		}
		free(str);
		if (count < 6)
			str = get_next_line(file);
	}
	free(func);
	return (count != 6);
}
