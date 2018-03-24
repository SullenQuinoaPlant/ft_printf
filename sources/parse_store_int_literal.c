#include "h.h"

char	*parse_store_int_literal(char const *in, int *** const p_res)
{
	int		val;
	char	*p_str;
	t_list	new_val;

	if ((p_str = parse_literal_integer(in, &val)) != in)
	{
		if ((new_val = ft_lstnew(&val, sizeof(int))))
		{
			in = p_str;
			ft_lstadd(&g_ps.p_literal_vals, new_val);
			*p_res = &new_val->content;
		}
		else
			g_ps.errored++;
	}
	return (in);
}
