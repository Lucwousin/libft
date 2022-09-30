/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   squicksort.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lsinke <lsinke@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/30 11:16:10 by lsinke        #+#    #+#                 */
/*   Updated: 2022/09/30 11:16:10 by lsinke        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <sort.h>

static void	*tri_median(t_sort *sort, size_t low, size_t high)
{
	uint32_t	mid;

	mid = (low + high) / 2;
	if (cmp(sort, get(sort, low), get(sort, mid)))
		swap(sort, mid, low);
	if (cmp(sort, get(sort, low), get(sort, high)))
		swap(sort, high, low);
	if (cmp(sort, get(sort, mid), get(sort, high)))
		swap(sort, mid, high);
	return (get(sort, mid));
}

static size_t	partition(t_sort *sort, size_t low, size_t high)
{
	void	*pivot;

	pivot = tri_median(sort, low, high);
	while (low < high)
	{
		while (!cmp(sort, get(sort, low), pivot))
			++low;
		while (cmp(sort, get(sort, high), pivot))
			--high;
		if (low < high)
			swap(sort, low, high);
	}
	return (low);
}

void	squicksort(t_sort *sort, size_t low, size_t high)
{
	size_t	partition_idx;

	if (low >= high)
		return ;
	if (high - low < INSERTION_SORT_CUTOFF)
		return (sinssort(sort, low, high));
	partition_idx = partition(sort, low, high);
	if (partition_idx != 0)
		squicksort(sort, low, partition_idx - 1);
	if (partition_idx != high)
		squicksort(sort, partition_idx + 1, high);
}
