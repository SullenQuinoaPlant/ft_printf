#ifndef APPENDABLE_LIST_H
# define APPENDABLE_LIST_H

# include "libft.h"

typedef union	u_appendable_list {
	t_list		head;
	t_list		*tail;
}				t_applist;

void
	my_lstappend(
		t_list **last, t_list *new);

#endif
