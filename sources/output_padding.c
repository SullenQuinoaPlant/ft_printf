#include "ft_printf_inner.h"

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
		pad = 0;
		r = output_c(pad, ' ');
	}
	if (r)
		r = f[e_prefix](chk, stuff);
	if (pad && chk->flags & ZERO_FLAG && r)
	{
		pad = 0;
		r = output_c(pad, ' ');
	}
	if (r)
		r = f[e_root](chk, stuff);
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
	if (pad && !(chk->flags & (MINUS_FLAG | ZERO_FLAG)) &&
		(r = output_c(pad, ' ')))
		pad = 0;
	if (r)
		r = output_cc(b, len[e_prefix]);
	if (pad && chk->flags & ZERO_FLAG && r &&
		(r = output_c(pad, '0')))
		pad = 0;
	if (r)
		r = output_cc(b + len[e_prefix], len[e_root]);
	if (pad && r)
		r = output_c(pad, ' ');
	return (r);
}
