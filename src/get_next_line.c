/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: lsinke <lsinke@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/20 12:58:22 by lsinke        #+#    #+#                 */
/*   Updated: 2022/04/20 12:58:22 by lsinke        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <get_next_line.h>
#include <unistd.h>
#include <dynarr.h>
#include <libft.h>

#define ERROR		0
#define DONE		1
#define CONTINUE	2

static t_list	*find_or_create_list(t_list **list, int fd)
{
	t_list		*cur;
	t_filebuf	*content;

	cur = *list;
	while (cur)
	{
		content = cur->content;
		if (content->fd == fd)
			return (cur);
		cur = cur->next;
	}
	cur = malloc(sizeof(t_list) + sizeof(t_filebuf));
	if (!cur)
		return (NULL);
	cur->content = cur + 1;
	content = cur->content;
	*content = (t_filebuf){fd, {}, 0, 0};
	ft_lstadd_front(list, cur);
	return (cur);
}

static int	add_til_newline(t_filebuf *buf, t_dynarr *linebuf)
{
	const char	*bufstart = buf->buf + buf->start;
	const char	*nl = ft_memchr(bufstart, '\n', buf->len);
	size_t		len;

	if (nl == NULL)
		len = buf->len;
	else
		len = nl - bufstart + 1;
	if (!dynarr_add(linebuf, bufstart, len))
		return (ERROR);
	buf->len -= len;
	buf->start += len;
	if (buf->len == 0)
		buf->start = 0;
	if (nl != NULL)
		return (DONE);
	else
		return (CONTINUE);
}

/**
 * Checks if leftover contains a newline. If not, read BUFFER_SIZE bytes
 * and append them onto leftover. Repeat.
 *
 * Returns NULL if anything went wrong
 */
static int	read_until_newline(int fd, t_filebuf *buf, t_dynarr *linebuf)
{
	ssize_t	read_bytes;
	int		result;

	while (true)
	{
		if (buf->len != 0)
		{
			result = add_til_newline(buf, linebuf);
			if (result != CONTINUE)
				return (result);
		}
		read_bytes = read(fd, buf->buf, BUFFER_SIZE);
		if (read_bytes < 0)
			return (ERROR);
		if (read_bytes == 0)
			return (DONE);
		buf->len = read_bytes;
	}
}

char	*get_next_line(int fd)
{
	static t_list	*list = NULL;
	t_list			*cur;
	int				result;
	t_dynarr		linebuf;

	if (fd < 0 || !dynarr_create(&linebuf, 128, sizeof(char)))
		return (NULL);
	cur = find_or_create_list(&list, fd);
	if (!cur)
		return (NULL);
	result = read_until_newline(fd, cur->content, &linebuf);
	if (result == ERROR || ((t_filebuf *) cur->content)->len == 0)
		ft_lstdelelem(&list, cur, NULL);
	if (result != ERROR && linebuf.length != 0)
		if (dynarr_addone(&linebuf, "\0") && dynarr_finalize(&linebuf))
			return (linebuf.arr);
	return (dynarr_delete(&linebuf), NULL);
}
