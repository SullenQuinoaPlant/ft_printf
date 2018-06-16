#include "ft_printf_inner.h"

static void 	init_parse_state()
{
	g_ps.chunks.head.next = 0;
	g_ps.chunks.tail = &g_ps.chunks.head;
	g_ps.p_req_args = 0;
	g_ps.p_known_vals = 0;
	g_ps.free_arg_count = 0;
	g_ps.dollar_count = 0;
	g_ps.max_arg_pos = 0;
	g_ps.errored = 0;
}

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

	init_parse_state();
	in = while_progress(strt, g_f_str);
	if (*in)
		g_ps.errored++;
	if (get_dollar_convention(&g_ps) == e_mix_dollar)
		g_ps.errored++;
	if (g_ps.free_arg_count > g_ps.max_arg_pos)
		g_ps.max_arg_pos = g_ps.free_arg_count;
	return (g_ps.errored ? 0 : 1);
}
