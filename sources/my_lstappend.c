#include "inner.h"

void	ft_lstappend(t_list **last, t_list *new)
{
	t_list	*nxt;

	nxt = *last;
	while ((nxt = nxt->next))
		*last = nxt;
	(**last).next = new;
	while ((nxt = new->next))
		new = nxt;
	*last = new;
}
