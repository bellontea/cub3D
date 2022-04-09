#include "libft.h"

int	ft_isspace(const char ch)
{
	if ((ch >= 9 && ch <= 13) || ch == 32)
		return (1);
	return (0);
}