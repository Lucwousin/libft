#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t len)
{
	char		*dp;
	const char	*sp;

	dp = dst;
	sp = src;
	while (len-- > 0)
		*dp++ = *sp++;
	return (dst);
}
