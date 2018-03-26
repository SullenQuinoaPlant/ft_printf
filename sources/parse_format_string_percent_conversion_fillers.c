#include "h.h"

char	*percent_conversion_dollar_arg(char const *in)
{
	t_s_pct *	const p_pct = ((t_s_cw*)g_ps.chunks.content)->data;
	char *		const p_str = in;
	int			val;

	if ((in = parse_fill_literal_int_dollar(in, &val)) != p_str)
	{
		p_pct->convertee->position = val;
	}
	return (in);
}

char	*percent_conversion_flags(char const *in)
{
	const char		flags[] = {'#', '0', '-', ' ', '+', '\''};
	const size_t	len = sizeof(flags) / sizeof(flags[0]);
	t_s_pct *		const p_pct = ((t_s_cw*)g_ps.chunks.content)->data;
	char *			p_res = &p_pct->flags;
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

char	*percent_conversion_width(char const *in)
{
	t_s_pct *	const p_pct = ((t_s_cw*)g_ps.chunks.content)->data;
	int ***		const p_res = &p_pct->width;
	char *		const p_str = in;

	if ((in = percent_conversion_star(in, p_res) == p_str))
		in = parse_store_int_literal(in, p_res);
	return (in);
}

char	*percent_conversion_precision(char const *in)
{
	t_s_pct *	const p_pct = ((t_s_cw*)g_ps.chunks.content)->data;
	int *** 	const p_res = &p_pct->precision;
	char		*p_str;

	if (*in == '.')
	{
		p_str = ++in;
		if ((in = percent_conversion_star(in, p_res)) == p_str)
			in = parse_store_int_literal(in, p_res);
	}
	return (in);
}

char	*percent_conversion_length_mod(char const *in)
{
	t_s_pct *	const p_pct = ((t_s_cw*)g_ps.chunks.content)->data;
	t_s_lmp		const mods[] = {
				{e_hh, "hh"},
				{e_h, "h"},
				{e_l, "l"},
				{e_ll, "ll"},
				{e_bigl, "L"},
				{e_j, "j"},
				{e_z, "z"},
				{e_t, "t"}};
	size_t		const len = sizeof(mods) / sizeof(mods[0]);
	int			i;

	if (*in)
	{
		i = -1;
		while (++i < len)
			if (! ft_strncmp(mods[i].str, in, ft_strlen(mods[i].str)))
			{
				p_pct->len_mod = mods[i].mod;
				in += ft_strlen(mods[i].str);
				break;
			}
		if (i == len)
			p_pct->len_mod = e_no_len;
	}
	return (in);
}

char	*percent_conversion_specifier(char const *in)
{
	t_s_pct *	const p_pct = ((t_s_cw*)g_ps.chunks.content)->data;
	char const	*specifiers = "aAcdeEfFgGinoupsxX"
	char		*p_str;

	if (*in && (p_str = ft_strchr(specifiers, *in)))
	{
		p_pct->specifier = (t_e_cs)(p_str - specifiers);
		in++;
	}
	else
		p_pct->specifier = e_no_specifier;
	return (in);
}
