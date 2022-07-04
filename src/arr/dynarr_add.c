/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   dynarr_add.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lsinke <lsinke@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/01 14:48:43 by lsinke        #+#    #+#                 */
/*   Updated: 2022/07/01 18:38:16 by lsinke        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <dynarr.h>
#include <libft.h>

/*
 * Grow by space still needed + GROW_SIZE, so we don't keep reallocating
 */
static size_t	calc_grow_size(t_dynarr *arr, size_t extra)
{
	return (extra - (arr->capacity - arr->length) + GROW_SIZE);
}

bool	dynarr_add(t_dynarr *arr, void *objs, size_t count)
{
	if (arr == NULL || objs == NULL)
		return (false);
	if (arr->capacity - arr->length < count)
		if (dynarr_grow(arr, calc_grow_size(arr, count)) == false)
			return (false);
	ft_memcpy(dynarr_get_u(arr, arr->length), objs, count * arr->elem_size);
	arr->length += count;
	return (true);
}

bool	dynarr_addone(t_dynarr *arr, void *obj)
{
	return (dynarr_add(arr, obj, 1));
}
