/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_realloc.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lsinke <lsinke@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/22 09:51:21 by lsinke        #+#    #+#                 */
/*   Updated: 2022/06/22 09:51:21 by lsinke        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_realloc(void *oldptr, size_t oldsize, size_t newsize)
{
	void	*newptr;
	size_t	copy_size;

	newptr = malloc(newsize);
	if (newptr == NULL)
		return (NULL);
	if (oldptr != NULL)
	{
		copy_size = ft_min(oldsize, newsize);
		ft_memcpy(newptr, oldptr, copy_size);
	}
	free(oldptr);
	return (newptr);
}
