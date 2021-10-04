void	*ft_memset(void *dest, int c, size_t len)
{
	unsigned char	*p;

	p = *dest;
	while (len-- > 0)
		*p++ = c;
	return dest;
}
