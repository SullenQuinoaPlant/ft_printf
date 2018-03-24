#include "h.h"

char	*star_raw(int **p_res)
{
	t_list	new_arg;

	if ((new_arg = ft_lstnew(&(t_s_arg){e_int, 0, 0}, sizeof(t_s_arg)))
}

char	*percent_conversion_star(char const *in, int **p_res)
{
	char	*p_str;

	if (*in == '*')
	{
		p_str = ++in;
		if ((in = star_literal(in, p_res) == p_str))
			star_raw(p_res);
	}
	return (in);
}
