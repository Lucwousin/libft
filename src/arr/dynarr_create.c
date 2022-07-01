/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   dynarr_create.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: lsinke <lsinke@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/01 14:32:14 by lsinke        #+#    #+#                 */
/*   Updated: 2022/07/01 14:32:14 by lsinke        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <dynarr.h>
#include <libft.h>

bool	dynarr_create(t_dynarr *ptr, size_t init_size, const size_t data_size)
{
	if (ptr == NULL || data_size == 0)
		return (false);
	*(size_t *) &ptr->data_size = data_size;
	ptr->arr_size = init_size;
	ptr->arr_idx = 0;
	ptr->arr = ft_calloc(init_size, data_size);
	return (ptr->arr != NULL);
}
