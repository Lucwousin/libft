#include "libft.h"

static size_t	find_size(long n)
{
	size_t	s;

	s = 0;
	if (n < 0)
	{
		n *= -1;
		++s;
	}
	while (n > 0)
	{
		++s;
		n /= 10;
	}
	return (s);
}

static void	itoa_rec(char *str, long n, size_t len)
{
	if (len-- == 0 || n == 0)
		return ;
	str[len] = (n % 10) + '0';
	itoa_rec(str, n / 10, len);
}

char	*ft_itoa(int n)
{
	char	*str;
	size_t	len;
	long	ln;

	ln = n;
	len = find_size(ln);
	if (len == 0)
		return (ft_strdup("0"));
	str = malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	if (ln < 0)
	{
		str[0] = '-';
		ln *= -1;
	}
	itoa_rec(str, ln, len);
	str[len] = '\0';
	return (str);
}
