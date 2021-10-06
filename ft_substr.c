#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ret;
	size_t	slen;
	size_t	n;

	slen = ft_strlen(s);
	if (len == 0 || start > slen)
		return (ft_strdup(""));
	ret = malloc((len + 1) * sizeof(char));
	if (!ret)
		return (NULL);
	if (start + len > slen)
		n = slen - start;
	else
		n = len;
	ft_memcpy(ret, s + start, n);
	ret[n] = '\0';
	return (ret);
}
