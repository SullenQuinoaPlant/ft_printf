#include "h.h"

static void	*star_raw(int **p_res)
{
	t_list	new_arg;

	if ((new_arg = ft_lstnew(&(t_s_arg){e_int, 0, 0}, sizeof(t_s_arg)))
	{
		ft_lstadd(&g_ps.p_req_args, new_arg);
		*p_res = ((t_s_arg*)new_arg->content)->p_arg;
		g_ps.arg_count++;
	}
	else
		g_ps.errored++;
}

static char	*star_literal(char const *in, int **p_res)
{
	char	*p_str;
	int		val;
	t_list	*new_arg;

	p_str = in;
	if ((in = parse_literal_integer(in, &val)) != p_str && *in++ == '$')
	{
		if ((new_val = ft_lstnew(&(t_s_arg){e_int, val, 0}, sizeof(t_s_arg))))
		{
			ft_lstadd(&g_ps.p_req_args, new_arg);
			*p_res = (
		
}

char		*percent_conversion_star(char const *in, int **p_res)
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
