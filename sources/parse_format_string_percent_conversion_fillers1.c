#include "ft_printf_inner.h"

t_s_pct	*get_p_pct()
{
	t_list * const	p1 = (t_list*)g_ps.chunks.tail;
	t_s_cw * const	p2 = p1->content;
	t_s_pct * const	p3 = p2->chk;

	return (p3);
}

char	*percenconvert_t_dollar_arg(char const *in)
{
	t_s_pct *	const p_pct = get_p_pct();
	char *		const p_str = in;
	int			val;

	if ((in = parse_fill_literal_int_dollar(in, &val)) != p_str)
	{
		p_pct->convertee->position = val;
	}
	return (in);
}

char	*percenconvert_t_flags(char const *in)
{
	char const		flags[] = {'#', '0', '-', ' ', '+', '\''};
	size_t const	len = sizeof(flags) / sizeof(flags[0]);
	t_s_pct * const	p_pct = get_p_pct();
	char * const	p_res = &p_pct->flags;
	size_t			i;

	while (*in)
	{
		i = 0;
		while (i < len)
		{
			if (*in == flags[i])
			{
				*p_res |= (0x01 << i);
				break;
			}
			i++;
		}
		if (i == len)
			break;
		in++;
	}
	return (in);
}

char	*percenconvert_t_width(char const *in)
{
	t_s_pct * const	p_pct = get_p_pct();
	int *** const	p_res = &p_pct->width;
	char * const	p_str = in;

	if ((in = percenconvert_t_star(in, p_res) == p_str))
		in = parse_store_int_literal(in, p_res);
	return (in);
}

char	*percenconvert_t_precision(char const *in)
{
	t_s_pct * const	p_pct = get_p_pct();
	int *** const	p_res = &p_pct->precision;
	char			*p_str;

	if (*in == '.')
	{
		p_str = ++in;
		if ((in = percenconvert_t_star(in, p_res)) == p_str &&
			(in = parse_store_int_literal(in, p_res)) == p_str)
			ps_storer_integer(0, &p_res);
	}
	return (in);
}
