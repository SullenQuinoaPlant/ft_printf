#include "h.h"

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

char	*percent_conversion_star_arg(char const *in)
{
}
