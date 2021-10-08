#include "libft.h"

char	*ft_strnstr(const char *str, const char *find, size_t n)
{
	size_t	len_f;
	size_t	off;
	char	*found;

	len_f = ft_strlen(find);
	if (len_f == 0)
		return ((char *) str);
	off = 0;
	while (1)
	{
		found = ft_memchr(str + off, find[0], n - off);
		if (!found)
			return (NULL);
		off = found - str + 1;
		if (off + len_f > n)
			return (NULL);
		if (ft_strncmp(found, find, len_f) == 0)
			return (found);
		found = NULL;
	}
}
