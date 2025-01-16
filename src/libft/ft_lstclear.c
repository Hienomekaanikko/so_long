#include "libft.h"

void ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*curr;

	while(*lst)
	{
		curr = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = curr;
	}
	free(*lst);
	*lst = NULL;
}
