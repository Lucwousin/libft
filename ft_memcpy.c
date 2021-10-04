void	*ft_memcpy(void *dst, const void *src, size_t len)
{
	char	*ptr;

	ptr = dst;
	while (len-- > 0)
		*ptr++ = *src++;
	return (dst);
}
