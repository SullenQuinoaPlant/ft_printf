#include "h.h"

char	*parse_literal_integer(char const *in, int	*p_res)
{
	int			res;
	t_list		*hold_res;

	if (! ft_isdigit(*in))
		return (in);
	res = 0;
	while (ft_isdigit(*in))
	{
		res *= 10;
		res += *in++ - '0';
	}
	*p_res = res;
	return (in)
}

char	*parse_fill_literal_int_dollar(char const *in, int * const to_fill)
{
	char	*p_str;
	int		val;

	p_str = in;
	if ((p_str = parse_literal_integer(in, &val)) != in && *p_str++ == '$')
	{
		*to_fill = val;
		g_ps.dollar_count++;
		g_ps.max_arg_pos = val > g_ps.max_arg_pos ? val : g_ps.max_arg_pos;
		in = p_str;
	}
	return (in);
}

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
