#include "libft.h"

static int	contains(const char *set, char val)
{
	while (*set)
		if (*set++ == val)
			return (1);
	return (0);
}

char	*ft_strtrim(char const *str, char const *set)
{
	char		*ret;
	const char	*end;
	size_t		len;

	while (contains(set, *str))
		++str;
	end = ft_strchr(str, 0) - 1;
	while (contains(set, *end))
		--end;
	len = end - str + 1;
	ret = malloc((len + 1) * sizeof(char));
	if (!ret)
		return (NULL);
	ft_strlcpy(ret, str, len + 1);
	return (ret);
}