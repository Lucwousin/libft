#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	n;

	n = 1;
	while (lst->next)
	{
		lst = lst->next;
		++n;
	}
	return (n);
}
