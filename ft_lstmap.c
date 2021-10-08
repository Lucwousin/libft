#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*map)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*cur;

	new_list = ft_lstnew(map(lst->content));
	if (!new_list)
		return (NULL);
	cur = new_list;
	while (lst->next)
	{
		lst = lst->next;
		cur->next = ft_lstnew(map(lst->content));
		cur = cur->next;
		if (!cur)
		{
			ft_lstclear(&new_list, del);
			return (NULL);
		}
	}
	return (new_list);
}