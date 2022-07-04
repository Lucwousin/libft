/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   dynarr_get.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lsinke <lsinke@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/01 14:58:44 by lsinke        #+#    #+#                 */
/*   Updated: 2022/07/01 14:58:44 by lsinke        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <dynarr.h>

void	*dynarr_get_u(t_dynarr *arr, size_t index)
{
	return (arr->arr + (index * arr->data_size));
}

void	*dynarr_get(t_dynarr *arr, size_t index)
{
	if (arr == NULL || index >= arr->arr_idx)
		return (NULL);
	return (dynarr_get_u(arr, index));
}
