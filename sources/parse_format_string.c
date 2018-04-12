#include "h.h"

t_s_ps	g_ps;

static void refresh_parse_state()
{
	g_ps.chunks = (t_list){0,0,&g_ps.chunks.tail_init};
	g_ps.p_req_args = 0;
	g_ps.p_literal_vals = 0;
	g_ps.free_arg_count = 0;
	g_ps.dollar_count = 0;
	g_ps.max_arg_pos = 0;
	g_ps.errored = 0;
}

t_e_dc	get_parse_dollar_convention(t_s_ps *s)
{
	if (g_ps.dollar_count)
	{
		if (free_arg_count && dollar_count)
			return (e_mix_dollar);
		else
			return (e_all_dollar);
	}
	return (e_no_dollar);
}

t_s_ps	parse_format_string(char const *in)
{
	char	*(* const f_str[])(char const *) = {
			parse_percent,
			parse_text,
			0};
	char	* const strt = in;

	refresh_parse_state();
	in = while_progress(strt, f_str);
	if (in == strt || *in)
		g_ps.errored++;
	if (get_parse_dollar_convention(&g_ps) == e_mix_dollar)
		g_ps.errored++;
	if (g_ps.free_arg_count > g_ps.max_arg_pos)
		g_ps.max_arg_pos = free_arg_count;
	return (g_ps);
}
