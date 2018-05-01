#include "h.h"

char		*percent_conversion_star(char const *in, int ***p_res)
{
	char	*p_str;
	t_list	*new_arg;
	int		*p_pos;

	if (*in == '*')
	{
		if ((new_arg = ft_lstnew(&(t_s_arg){e_int, 0, 0}, sizeof(t_s_arg)))
		{
			ft_lstadd(&g_ps.p_req_args, new_arg);
			*p_res = &((t_s_arg*)new_arg->content)->p_val;
			in++;
			p_pos = &((t_s_arg*)new_arg->content)->position;
			in = parse_fill_literal_int_dollar(in, p_pos);
			if (! *p_pos)
				*p_pos = (++g_ps.free_arg_count);
		}
		else
			g_ps.errored++;
	}
	return (in);
}
