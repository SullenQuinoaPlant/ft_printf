#include "h.h"

t_s_ps	g_ps;

static void refresh_parse_state()
{
	if (g_ps.p_out_bits)
		ft_lstdel(&g_ps.p_out_bits, ft_bzero);
	if (g_ps.p_req_args)
		ft_lstdel(&g_ps.p_req_args, ft_bzero);
	if (g_ps.p_literal_vals)
		ft_lstdel(&g_ps.p_literal_vals, my_clean_free);
	g_ps.arg_count = 0;
	g_ps.dollar_count = 0;
}

int		parse_format_string(char const *in)
{
	char	*(* const f_str[])(char const *) = {
			parse_percent,
			parse_text,
			0};
	char	* const strt = in;
	int		i;

	refresh_parse_state();
	i = -1;
	while (f_str[++i] && strt == in)
		in = f_str[i](in);
	if (in == strt || *in)
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
