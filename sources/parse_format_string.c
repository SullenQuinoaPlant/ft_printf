#include "h.h"

t_s_ps	g_ps;

static void	clean_free_cw(void *ptr, size_t whatever)
{
	(void)whatever;
	t_s_cw * const	p_cw = (t_s_cw*)ptr;
	size_t			sz;
	t_e_cts			*p;

	if (! p_cw)
		return;
	p = &p_cw->type;
	sz = 0;
	if (*p == e_txt_c)
		sz = sizeof(t_s_text);
	else if (*p == e_char_c)
		sz = sizeof(t_s_char);
	else if (*p == e_pct_c)
		sz = sizeof(t_s_pct);
	if (p_cw->data)
		my_clean_free(p_cw->data, sz);
	*p_cw = (t_s_cw){0,0};
	free(p_cw);
}

static void refresh_parse_state()
{
	if (g_ps.out_bits_anchor.next)
		ft_lstdel(&g_ps.chunks.next, clean_free_cw);
	g_ps.chunks.content = 0;
	if (g_ps.p_req_args)
		ft_lstdel(&g_ps.p_req_args, my_clean_free);
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
