/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_free_mult.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: lsinke <lsinke@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/21 13:25:22 by lsinke        #+#    #+#                 */
/*   Updated: 2022/04/21 13:25:22 by lsinke        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_free_mult(void **a)
{
	void	**p;

	p = a;
	while (*a)
		free(*a++);
	free(p);
}
