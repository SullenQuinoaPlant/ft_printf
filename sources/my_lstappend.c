#include "h.h"

void	my_lstappend(t_lst **last, t_list *new)
{
	t_list	*nxt;

	(**last).next = new;
	while ((nxt = new->next))
		new = nxt;
	*last = new;
}
