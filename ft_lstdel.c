#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (del)
		del(lst->content);
	free(lst);
}

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*cur;
	t_list	*nxt;

	nxt = *lst;
	while (nxt)
	{
		cur = nxt;
		nxt = cur->next;
		ft_lstdelone(cur, del);
	}
	*lst = NULL;
}
