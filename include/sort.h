/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort.h                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: lsinke <lsinke@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/30 12:59:16 by lsinke        #+#    #+#                 */
/*   Updated: 2022/09/30 12:59:16 by lsinke        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORT_H
# define SORT_H

# include <stdbool.h>
# include <stddef.h>
# include <stdint.h>

# define INSERTION_SORT_CUTOFF	10

typedef void	*(*t_get)(void *objs, size_t idx);
typedef void	(*t_set)(void *objs, size_t idx, void *val);
typedef bool	(*t_cmp)(void *a, void *b);
typedef void	(*t_swap)(void *objs, size_t idx_a, size_t idx_b);

typedef struct s_sort_data {
	void	*objs;
	t_get	get;
	t_set	set;
	t_cmp	cmp;
	t_swap	swap;
}	t_sort;

void	quicksort(int32_t *arr, uint32_t low, uint32_t high);
void	squicksort(t_sort *sort, size_t low, size_t high);

void	inssort(int32_t *arr, uint32_t low, uint32_t high);
void	sinssort(t_sort *sort, size_t low, size_t high);

static inline void	*get(t_sort *s, size_t i)
{
	return (s->get(s->objs, i));
}

static inline void	set(t_sort *s, size_t i, void *v)
{
	return (s->set(s->objs, i, v));
}

static inline bool	cmp(t_sort *s, void *a, void *b)
{
	return (s->cmp(a, b));
}

static inline void	swap(t_sort *s, size_t i, size_t j)
{
	return (s->swap(s->objs, i, j));
}

#endif