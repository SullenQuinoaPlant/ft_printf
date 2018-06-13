#include "ft_printf_inner.h"

static int	output_padding(size_t yay_much, char of_this)
{
	size_t	much_yay;

	much_yay = yay_much;
	while (yay_much--)
		if (write(g_os.fd, &of_this, 1) != 1)
		{
			g_os.errored++;
			break;
		}
	g_os.output_len += much_yay - ++yay_much;
	return (yay_much == 0);
}

static int	get_padlen(t_s_pct *p_chk, size_t len)
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
	if (pad && chk->flags & MINUS_FLAG)
	{
		pad = 0;
		r = output_padding(pad, ' ');
	}
	if (r)
		r = f[e_oi_prefix](chk, stuff);
	if (pad && chk->flags & ZERO_FLAG && r)
	{
		pad = 0;
		r = output_padding(pad, ' ');
	}
	if (r)
		r = f[e_oi_body](chk, stuff);
	if (pad && r)
		output_padding(pad, ' ');
}

int			output_padnbuffer(
	char *b, size_t len[], t_s_pct *chk)
{
	ssize_t			out;
	int				r;
	int				pad;

	pad = get_padlen(chk, len[e_prefix] + len[e_root]);
	r = 1;
	if (pad && chk->flags & MINUS_FLAG &&
		(r = output_padding(pad, ' ')))
		pad = 0;
	if (r)
		r = output_raw(b, len[e_prefix]);
		r = output((t_s_cc){b, len[e_prefix]});
	if (pad && chk->flags & ZERO_FLAG && r &&
		(r = output_padding(pad, '0')))
		pad = 0;
	b += len[e_prefix];
	if (r)
		r = output((t_s_cc){b, len[e_root]});
	if (pad && r)
		r = output_padding(pad, ' ');
	return (r);
}
