#include "ft_printf_inner.h"

char const	*percent_convert_star(
	char const *in, int ***p_res)
{
	t_s_arg const	init = (t_s_arg){e_int, {0}, 0};
	t_list	*p_arg;
	int		*p_pos;

	if (*in != '*')
		return (in);
	if ((p_arg = ft_lstnew(&init, sizeof(init))))
	{
		ft_lstadd(&g_ps.p_req_args, p_arg);
		*p_res = (int**)&((t_s_arg*)p_arg->content)->p_val;
		in++;
		p_pos = &((t_s_arg*)p_arg->content)->position;
		in = parse_fill_literal_int_dollar(in, p_pos);
		if (! *p_pos)
			*p_pos = (++g_ps.free_arg_count);
	}
	else
		g_ps.errored++;
	return (in);
}
