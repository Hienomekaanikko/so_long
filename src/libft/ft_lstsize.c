#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*curr;
	int		i;

	curr = lst;
	i = 0;
	while(curr)
	{
		curr = curr->next;
		i++;
	}
	return (i);
}
