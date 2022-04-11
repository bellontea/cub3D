/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   head_parcer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjamis <tjamis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 16:29:49 by tjamis            #+#    #+#             */
/*   Updated: 2022/04/11 21:14:10 by tjamis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*skip_space(int file)
{
	char	*str;
	char	*temp;
	int		i;

	str = get_next_line(file);
	while (str)
	{
		temp = str;
		i = 0;
		while (temp[i] && ft_isspace(temp[i]))
			i++;
		if (temp[i])
			return (str);
		free(str);
		str = get_next_line(file);
	}
	return (str);
}

int	check_key(char *str, int count, t_all *vars)
{
	const char	*identifier[] = {"C", "F", "NO", "SO", "WE", "EA", NULL};
	int			(**func)(t_all *, char *);
	int			i;

	func = init_head_parcer();
	i = 0;
	while (identifier[i])
	{
		if (!ft_strncmp(identifier[i], str, ft_strlen(identifier[i])))
		{
			count += 1 + func[i](vars, str + ft_strlen(identifier[i])) * 10;
			break ;
		}
		i++;
	}
	free(func);
	if (identifier[i])
		return (count);
	return (100);
}

int	head_parcer(t_all *vars, int file)
{
	char		*str;
	int			count;

	count = 0;
	vars->color_c = -1;
	vars->color_f = -1;
	str = skip_space(file);
	while (count < 6 && str)
	{
		count = check_key(str, count, vars);
		free(str);
		if (count < 6)
			str = skip_space(file);
	}
	return (count != 6);
}
