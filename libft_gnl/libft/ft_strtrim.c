/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mslyther <mslyther@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 17:51:55 by mslyther          #+#    #+#             */
/*   Updated: 2022/01/19 17:51:56 by mslyther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_symbol(char c, const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (s[i] == c);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	size;
	char	*result;

	if (!s1 || !set)
		return (NULL);
	size = 0;
	while (*s1 && is_symbol(*s1, set))
		s1++;
	size = ft_strlen(s1);
	while (size && is_symbol(s1[size - 1], set))
		size--;
	result = malloc(size + 1);
	if (!result)
		return (NULL);
	ft_strlcpy(result, s1, size + 1);
	return (result);
}
