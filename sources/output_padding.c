#include "inner.h"

int		get_padlen(t_s_pct *p_chk, size_t len)
{
	int		pad;

	pad = p_chk->width ? **p_chk->width : 0;
	if ((size_t)pad > len)
		pad -= len;
	else
		pad = 0;
	return (pad);
}

static int
	output_zero_pad(
		size_t len)
{
	t_s_so	pad;

	pad.len = len;
	pad.c = '0';
	if ((pad.type = g_os.apstr_grp ? e_sot_apstr_c : e_sot_c) != e_sot_c)
		apstrify_zpad(g_os.apstr_grp, &pad, &g_os.apstr_pos);
	return (output_syllable(&pad));
}

void		output_padnstuff(
	size_t len, t_s_pct *chk,
	t_outputter const f[], void *stuff)
{
	int				r;
	int				pad;

	pad = get_padlen(chk, len);
	r = 1;
	if (pad && !(chk->flags & (MINUS_FLAG | ZERO_FLAG)))
	{
		r = output_c(pad, ' ');
		pad = 0;
	}
	if (r)
		r = f[e_prefix](stuff);
	if (pad && chk->flags & ZERO_FLAG && r)
	{
		r = output_zero_pad(pad);
		pad = 0;
	}
	if (r)
		r = f[e_root](stuff);
	if (pad && r)
		output_c(pad, ' ');
}

int			output_padnbuffer(
	char *b, size_t len[], t_s_pct *chk)
{
	int				r;
	int				pad;

	pad = get_padlen(chk, len[e_prefix] + len[e_root]);
	r = 1;
	if (pad &&
		!(chk->flags & (MINUS_FLAG | ZERO_FLAG)) &&
		(r = output_c(pad, ' ')))
		pad = 0;
	if (r)
		r = output_cc(len[e_prefix], b);
	if (pad && chk->flags & ZERO_FLAG && r &&
		(r = output_c(pad, '0')))
		pad = 0;
	if (r)
		r = output_cc(len[e_root], b + len[e_prefix]);
	if (pad && r)
		r = output_c(pad, ' ');
	return (r);
}
