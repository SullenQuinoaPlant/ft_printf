#include "ft_printf_inner.h"

t_s_pct	*get_p_pct()
{
	t_s_cw	* const p1 = g_ps.chunks.tail->content;
	t_s_pct * const	p2 = p1->chk;

	return (p2);
}

char const	*percent_convert_dollar_arg(char const *in)
{
	char const	* const p_str = in;
	t_s_pct		*p_pct;
	int			val;

	p_pct = get_p_pct();
	if ((in = parse_fill_literal_int_dollar(in, &val)) != p_str)
		p_pct->vaarg->position = val;
	return (in);
}

#define FLAG_COUNT 6
char const	*percent_convert_flags(char const *in)
{
	char const		* const flags = "#0- +'";
	char			*p_res;
	size_t			i;

	p_res = &(get_p_pct())->flags;
	i = 0;
	while (*in && i < FLAG_COUNT)
	{
		i = -1;
		while (++i < FLAG_COUNT)
			if (*in == flags[i])
			{
				*p_res |= (0x01 << i);
				in++;
				break;
			}
	}
	return (in);
}
#undef FLAG_COUNT

char const	*percent_convert_width(char const *in)
{
	char const	* const p_str = in;
	int **		*p_res;

	p_res = &(get_p_pct())->width;
	if ((in = percent_convert_star(in, p_res)) == p_str)
		in = parse_store_int_literal(in, p_res);
	return (in);
}

char const	*percent_convert_precision(char const *in)
{
	char const	*p_str;
	int **	*p_res;

	if (*in != '.')
		return (in);
	p_res = &(get_p_pct())->precision;
	p_str = ++in;
	if ((in = percent_convert_star(in, p_res)) == p_str &&
		(in = parse_store_int_literal(in, p_res)) == p_str)
		ps_store_integer(0, p_res);
	return (in);
}
