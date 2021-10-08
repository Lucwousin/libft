#include "libft.h"

static void	get_lens(const char *s1, const char *s2, size_t *l1, size_t *l2)
{
	if (s1)
		*l1 = ft_strlen(s1);
	else
		*l1 = 0;
	if (s2)
		*l2 = ft_strlen(s2);
	else
		*l2 = 0;
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*str;
	size_t	l1;
	size_t	l2;
	size_t	len;

	get_lens(s1, s2, &l1, &l2);
	if (l1 == 0 && l2 == 0)
		return (ft_strdup(""));
	if (l1 == 0)
		return (ft_strdup(s2));
	if (l2 == 0)
		return (ft_strdup(s1));
	len = l1 + l2 + 1;
	str = malloc(len * sizeof(char));
	if (!str)
		return (NULL);
	ft_memcpy(str, s1, l1);
	ft_memcpy(str + l1, s2, l2);
	str[len - 1] = '\0';
	return (str);
}
