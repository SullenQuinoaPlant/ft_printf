#include "h.h"

t_s_ps	g_ps;

static void refresh_parse_state()
{
	if (g_ps.out_bits_anchor.next)
		ft_lstdel(&g_ps.out_bits_anchor.next, ft_bzero);
	g_ps.out_bits_anchor.content = 0;
	if (g_ps.p_req_args)
		ft_lstdel(&g_ps.p_req_args, ft_bzero);
	if (g_ps.p_literal_vals)
		ft_lstdel(&g_ps.p_literal_vals, my_clean_free);
	g_ps.arg_count = 0;
	g_ps.dollar_count = 0;
	g_ps.max_arg_pos = 0;
	g_ps.errored = 0;
}

int		parse_format_string(char const *in)
{
	char	*(* const f_str[])(char const *) = {
			parse_percent,
			parse_text,
			0};
	char	* const strt = in;

	refresh_parse_state();
	in = while_progress(strt, f_str);
	if (in == strt || *in || g_ps.errored)
	{
		refresh_parse_state();
		return (-1);
	}
	return (0);
}

t_e_dc	get_parse_dollar_convention(t_s_ps *s)
{
	if (g_ps.dollar_count)
	{
		if (g_ps.arg_count > g_ps.dollar_count)
			return (e_mix_dollar);
		else
			return (e_all_dollar);
	}
	return (e_no_dollar);
}
