void	*ft_memset(void *dst, int c, size_t len)
{
	unsigned char	*p;

	p = dst;
	while (len-- > 0)
		*p++ = c;
	return (dst);
}
