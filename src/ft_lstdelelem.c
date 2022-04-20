/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstdelelem.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: lucas <lucas@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/20 14:11:45 by lucas         #+#    #+#                 */
/*   Updated: 2022/04/20 14:11:45 by lucas         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */
#include "../include/libft.h"

void	ft_lstdelelem(t_list **list, t_list *elem, void (*del)(void *))
{
	t_list	*cur;

	if (elem == *list)
	{
		*list = elem->next;
	}
	else
	{
		cur = *list;
		while (cur->next != elem)
			cur = cur->next;
		cur->next = elem->next;
	}
	ft_lstdelone(elem, del);
}
