#ifndef LIBFT_H
# define LIBFT_H
#include <unistd.h>
#include <stdlib.h>

int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
size_t	ft_strlen(const char *str);
void	*ft_memset(void *dst, int c, size_t len);
void	ft_bzero(void *dst, size_t len);
void	*ft_memcpy(void *dst, const void *src, size_t len);
void	*ft_memmove(void *dst, const void *src, size_t len);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstlen);
size_t	ft_strlcat(char *dst, const char *src, size_t dstlen);
int		toupper(int c);
int		tolower(int c);

#endif /* LIBFT_H */
