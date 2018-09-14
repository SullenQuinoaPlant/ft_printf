#include "inner.h"

static t_s_pct	*pct_chk_init()
{
	t_s_pct	*pct_chk;

	if ((pct_chk = malloc(sizeof(t_s_pct))))
	{
		pct_chk->flags = NO_FLAGS;
		pct_chk->width = 0;
		pct_chk->precision = 0;
		pct_chk->len_mod = e_no_len;
		pct_chk->specifier = e_no_specifier;
		pct_chk->vaarg = 0;
	}
	return (pct_chk);
}

static char const *
	(* const g_f_str[])(char const *) = {
			percent_convert_dollar_arg,
			percent_convert_flags,
			percent_convert_width,
			percent_convert_precision,
			percent_convert_length_mod,
			percent_convert_specifier,
			0};

char const		*parse_convert(char const *in)
{
	char const	* const save = in;
	t_s_cw 		* const cw = g_ps.chunks.tail->content;
	t_s_pct		*chk;
	t_s_arg		*arg;

	if ((arg = req_arg_init()) &&
		(chk = pct_chk_init()))
	{
		*cw = (t_s_cw){e_pct_c, chk};
		chk->vaarg = arg;
		in = attempt_all(in, g_f_str);
		if (!arg->position)
			arg->position = (++g_ps.free_arg_count);
		arg->type = get_etype(chk->specifier, chk->len_mod);
		if (arg->type == e_notype)
			in = save;
	}
	else
		g_ps.errored++;
	return (in);
}
