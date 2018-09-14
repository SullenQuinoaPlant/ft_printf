#include "inner.h"

static t_e_dc	get_dollar_convention()
{
	if (g_ps.dollar_count)
	{
		if (g_ps.free_arg_count)
			return (e_mix_dollar);
		else
			return (e_all_dollar);
	}
	return (e_no_dollar);
}

static char const *
	(*const g_f_str[])(char const *) = {
		parse_percent,
		parse_text,
		0};

int				parse_format_string(char const *in)
{
	char const	* const strt = in;

	in = while_progress(strt, g_f_str);
	if (*in)
		g_ps.errored++;
	if (get_dollar_convention(&g_ps) == e_mix_dollar)
		g_ps.errored++;
	if (g_ps.free_arg_count > g_ps.max_arg_pos)
		g_ps.max_arg_pos = g_ps.free_arg_count;
	return (!g_ps.errored);
}
