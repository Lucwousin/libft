#include "libft.h"

static int	contains(const char *set, char c)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		++set;
	}
	return (0);
}

int	ft_atoi(const char *str)
{
	int		sign;
	long	val;

	sign = 1;
	val = 0;
	while (contains("\t\n\v\f\r ", *str))
		++str;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		++str;
	}
	while (ft_isdigit(*str))
	{
		val *= 10;
		val += *str - '0';
		++str;
	}
	return ((int) val * sign);
}
