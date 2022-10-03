/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   kdtree.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: lsinke <lsinke@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/01 18:21:53 by lsinke        #+#    #+#                 */
/*   Updated: 2022/10/01 18:21:53 by lsinke        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef KDTREE_H
# define KDTREE_H

# include <stdbool.h>
# include <stddef.h>
# include <stdint.h>

# define LEAF_SIZE	16

typedef int	(*t_cmp)(void *a, void *b, uint8_t axis);

typedef struct s_kdnode	t_kdnode;

typedef enum e_kdflags {
	IS_LEAF,

}	t_kdflags;

struct s_kdnode {
	union {
		struct {
			void		*point;
			t_kdnode	*l;
			t_kdnode	*r;
		};
		struct {
			void		*points[LEAF_SIZE];
			uint8_t		plen;
		};
	};
	void		*min;
	void		*max;
	t_kdflags	flags;
	uint8_t		axis;
};

typedef struct s_kdtree {
	const uint8_t	k;
	t_kdnode		root;
	t_cmp			cmp;
}	t_kdtree;

bool	kdtree(void *objs[], size_t length, uint8_t k, t_kdtree *dst);

#endif //KDTREE_H
