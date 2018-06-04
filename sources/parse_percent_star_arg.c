#include "ft_printf_inner.h"

char		*percenconvert_t_star(char const *in, int ***p_res)
{
	char	*p_str;
	t_list	*p_arg;
	int		*p_pos;

	if (*in != '*')
		return (in);
	if ((p_arg = ft_lstnew(&(t_s_arg){e_int, 0, 0}, sizeof(t_s_arg)))
	{
		ft_lstadd(&g_ps.p_req_args, p_arg);
		*p_res = &((t_s_arg*)p_arg->content)->p_val;
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
