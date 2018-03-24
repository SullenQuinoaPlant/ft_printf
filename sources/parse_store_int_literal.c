#include "h.h"

char	*parse_store_int_literal(char const *in, int ** const p_res)
{
	int		val;
	char	*p_str;
	t_list	new_val;

	p_str = in;
	if ((in = parse_literal_integer(in, &val)) != p_str)
	{
		if ((new_val = ft_lstnew(&val, sizeof(int))))
		{
			ft_lstadd(&g_ps.p_literal_vals, new_val);
			*p_res = new_val->content;
		}
		else
			g_ps.errored++;
	}
	return (in);
}
