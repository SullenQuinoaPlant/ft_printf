#include "h.h"

char	*parse_conversion(char const *in)
{
	char		*(* const f_str[])(char const *) = {
				percent_conversion_dollar_arg,
				percent_conversion_flags,
				percent_conversion_width,
				percent_conversion_precision,
				percent_conversion_length_mod,
				percent_conversion_specifier,
				0};
	t_s_cw *	const p_cw = g_ps.chunks.content;
	t_s_pct		*p_chk;
	t_list		*p_arg;

	if (! *in)
		return (in);
	if ((p_arg = ft_lstnew(&((t_s_arg){e_notype, 0, 0}), sizeof(t_s_arg))) &&
		(p_chk = malloc(sizeof(t_s_pct))))
	{
		ft_lstadd(&g_ps.p_req_args, p_arg);
		g_ps.arg_count++;
		*p_chk = (t_s_pct){NO_FLAGS, 0, 0, e_no_len, '\0', p_arg->content};
		*p_cw = (t_s_cw){e_pct_c, p_chk};
		in = attempt_all(in, f_str);
	}
	else
	{
		if (p_arg)
			my_clean_free(p_arg, sizeof(t_s_arg));
		g_ps.errored++;
	}
	return (in);
}
