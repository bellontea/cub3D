#include "cub3d.h"

void	add_space(char **str)
{
	int		i;
	char	*tmp;

	if (!str[0])
		return ;
	tmp = ft_strchr(str[0], '\t');
	while (tmp)
	{
		i = ft_strlen(str[0]);
		str[0] = ft_realloc(str[0], i, i + 4);
		tmp = ft_strchr(str[0], '\t');
		i += 3;
		while (&str[0][i - 3] != tmp)
		{
			str[0][i] = str[0][i - 3];
			i--;
		}
		while (&str[0][i] != tmp)
		{
			str[0][i] = ' ';
			i--;
		}
		str[0][i] = ' ';
		tmp = ft_strchr(str[0], '\t');
	}
}

void	skip_empty(t_all *vars, int file)
{
	int	i;

	vars->map = ft_calloc(2, sizeof(char *));
	vars->map[0] = get_next_line(file);
	while (vars->map[0])
	{
		i = 0;
		while (vars->map[0][i])
		{
			if (!ft_isspace(vars->map[0][i]))
				return ;
			i++;
		}
		free(vars->map[0]);
		vars->map[0] = get_next_line(file);
	}
}

int	map_parcer(t_all *vars, char *file_name)
{
	int	file;
	int	i;

	file = open(file_name, O_RDONLY);
	if (file == -1 || head_parcer(vars, file))
		return (1);
	i = 0;
	skip_empty(vars, file);
	while (vars->map[i])
	{
		if (set_player(vars, i))
		{
			printf("error player set\n");
			close(file);
			return (1);
		}
		add_space(vars->map + i);
		i++;
		vars->map = ft_realloc(vars->map, i * sizeof(char *),
				(i + 2) * sizeof(char *));
		vars->map[i] = get_next_line(file);
	}
	close(file);
	return (check_map(vars->map));
}
