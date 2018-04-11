#ifndef APPENDABLE_LIST_H
# define APPENDABLE_LIST_H

# include "libft.h"

typedef union	u_appendable_list {
	t_list	tail_init;
	struct	{
		void	*tail;
		size_t	unused;
		t_list	*head;
	};
}				t_applist;

#endif
