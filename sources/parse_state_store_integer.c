#include "ft_printf.h"

int		**ps_store_integer(int val, int *** const p_res)
{
	t_list	new_val;

	p_res = 0;
	if ((new_val = ft_lstnew(&val, sizeof(int))))
	{
		ft_lstadd(&g_ps.p_literal_vals, new_val);
		*p_res = &new_val->content;
	}
	else
		g_ps.errored++;
	return (*p_res);
}
