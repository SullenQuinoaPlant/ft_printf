#include "ft_printf_inner.h"

char	*parse_literal_integer(char const *in, int	*p_res)
{
	int			res;

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

char	*parse_fill_literal_int_dollar(char const *in,
										int * const to_fill)
{
	char	*p_str;
	int		val;
	int		d;

	p_str = in;
	if ((p_str = parse_literal_integer(in, &val)) != in &&
		*p_str++ == '$')
	{
		*to_fill = val;
		g_ps.dollar_count++;
		g_ps.max_arg_pos += (d = val - g_ps.max_arg_pos) > 0 ? d : 0;
		in = p_str;
	}
	return (in);
}

char	*parse_store_int_literal(char const *in, int *** const p_res)
{
	int		val;
	char	*p_str;

	if ((p_str = parse_literal_integer(in, &val)) != in)
	{
		ps_store_integer(val, p_res);
		in = p_str;
	}
	return (in);
}
