#include "h.h"

static char	*star_literal_dollar(char const *in, t_list *new_arg)
{
	char	*p_str;
	int		val;

	p_str = in;
	if ((p_str = parse_literal_integer(in, &val)) != in && *p_str++ == '$')
	{
		((t_s_arg*)new_arg->content)->position = val;
		g_ps.dollar_count++;
		g_ps.max_arg_pos = val > g_ps.max_arg_pos ? val : g_ps.max_arg_pos;
		in = p_str;
	}
	return (in);
}

char		*percent_conversion_star(char const *in, int ***p_res)
{
	char	*p_str;
	t_list	new_arg;

	if (*in == '*')
	{
		if ((new_arg = ft_lstnew(&(t_s_arg){e_int, 0, 0}, sizeof(t_s_arg)))
		{
			ft_lstadd(&g_ps.p_req_args, new_arg);
			*p_res = &((t_s_arg*)new_arg->content)->p_arg;
			g_ps.arg_count++;
			in++;
			in = star_literal_dollar(in, new_arg);
		}
		else
			g_ps.errored++;
	}
	return (in);
}
