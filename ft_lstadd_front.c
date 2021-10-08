#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *nw)
{
	nw->next = *lst;
}
