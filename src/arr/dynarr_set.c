/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   dynarr_set.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lsinke <lsinke@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/01 15:00:24 by lsinke        #+#    #+#                 */
/*   Updated: 2022/07/01 15:00:24 by lsinke        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <dynarr.h>
#include <libft.h>

bool	dynarr_set(t_dynarr *arr, size_t index, void *obj)
{
	if (arr == NULL)
		return (false);
	if (index >= arr->arr_size)
		if (dynarr_grow(arr, index + 1) == false)
			return (false);
	ft_memcpy(arr->arr + (index * arr->data_size), obj, arr->data_size);
	return (true);
}
