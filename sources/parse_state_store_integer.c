#include "inner.h"

int	**
	ps_store_integer(
		int val, int *** const p_res)
{
	t_list	*new_val;

	if ((new_val = ft_lstnew(&val, sizeof(int))))
	{
		ft_lstadd(&g_ps.p_known_vals, new_val);
		*p_res = (int**)&new_val->content;
		return ((int**)new_val->content);
	}
	else
		g_ps.errored++;
	return (0);
}
