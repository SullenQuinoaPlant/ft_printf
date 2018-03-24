#include "h.h"

char	*percent_conversion_width_literal(char const *in)
{
	int ***	const p_res = &((t_s_pct*)g_ps.chunks.content)->width;

	return ((in = parse_store_int_literal(in, p_res));
}

char	*percent_conversion_star_arg(char const *in)
{
}

//HAS TO MOVE:
char	*dollar(char const *in, int val, int const ** const p_res)
{
	t_list	*new_arg;

	if (! *in == '$')
	{
		if ((new_arg = ft_lstnew(&(t_s_arg){e_int, val, 0}, sizeof(t_s_arg))))
		{
			ft_lstadd(&g_ps.p_req_args, new_arg);
			*p_res = &new_arg->position;
			in++;
		}
		else
			g_ps.errored++;
	}
	return (in);
}
