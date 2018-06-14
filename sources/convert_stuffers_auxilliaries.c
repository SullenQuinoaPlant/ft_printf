#include "ft_printf_inner.h"

void
	stuff_stuff(
		t_stuffer *f_str, void *p_stf,
		int *dummy_indexes)
{
	t_stuffer	f;
	int			dummy_i;
	int			i;

	dummy_i = 0;
	i = -1;
	while ((f = f_str[++i]))
		if (f == &dummy_stuffer)
			dummy_indexes[dummy_i++] = i;
		else
			(*f)(i, p_stf);
}

void	dummy_stuffer(int i, void *v)
{
	(void)i;
	(void)v;
	(void)t;
}

