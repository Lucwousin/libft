#include "libft.h"

/**
 * Returns a pointer to the first character of a word
 */
static char	*find_next_word(const char *str, char c)
{
	char	*p;

	p = ft_strchr(str, c);
	if (p == NULL)
		return (NULL);
	while (*p == c)
		++p;
	if (!*p)
		return (NULL);
	return (p);
}

static size_t	count_words(const char *str, char c)
{
	size_t	n;
	char	*p;

	n = 0;
	p = (char *) str;
	while (1)
	{
		p = find_next_word(p, c);
		if (!p)
			return (n);
		++n;
	}
}

static void	do_splitting(const char *str, char c, char **strs, size_t n_words)
{
	char	*word;
	int		wl;
	size_t	i;

	i = 0;
	word = (char *) str;
	while (i < n_words)
	{
		word = find_next_word(word, c);
		wl = ft_strchr(word, c) - word;
		strs[i] = ft_substr(word, 0, wl);
		++i;
	}
}

char	**ft_split(const char *str, char c)
{
	char	**strs;
	size_t	n_words;

	n_words = count_words(str, c);
	strs = malloc((n_words + 1) * sizeof(char *));
	if (!strs)
		return (NULL);
	strs[n_words] = NULL;
	do_splitting(str, c, strs, n_words);
	return (strs);
}
