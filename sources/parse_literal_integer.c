#include "ft_printf_inner.h"

char const	*parse_literal_uint(
	char const *in, unsigned int *p_res)
{
	int			res;

	if (!ft_isdigit(*in))
		return (in);
	res = 0;
	while (ft_isdigit(*in))
	{
		res *= 10;
		res += *in++ - '0';
	}
	*p_res = res;
	return (in);
}

char const	*parse_fill_literal_int_dollar(
	char const *in, int * const to_fill)
{
	char const		*p_s;
	unsigned int	val;

	p_s = in;
	if ((p_s = parse_literal_uint(in, &val)) != in &&
		*p_s++ == '$')
	{
		*to_fill = val;
		g_ps.dollar_count++;
		if (val > g_ps.max_arg_pos)
			g_ps.max_arg_pos = val;
		in = p_s;
	}
	return (in);
}

char const	*parse_store_int_literal(
	char const *in, int *** const p_res)
{
	unsigned int	val;
	char const		*p_str;

	if ((p_str = parse_literal_uint(in, &val)) != in)
	{
		ps_store_integer(val, p_res);
		in = p_str;
	}
	return (in);
}
