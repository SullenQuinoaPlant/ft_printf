#include "h.h"

int		output_padding(size_t yay_much, char of_this)
{
	ssize_t	outputten;

	outputten = write(g_os.out_stream, &of_this, yay_much);
	g_os.output_len += outputten;
	if (outputten < yay_much)
	{
		g_os.errored++;
		return (0);
	}
	return (1);
}

int		output_padnstuff(size_t len, t_s_pct *p_chk,
					ssize_t (*outputer)(void*), void *stuff)
{
	int		r;
	int		pad;

	r = 1;
	if ((pad = **p_chk->width) > 0 && pad > len && (pad -= len) &&
		p_chk->flags & MINUS_FLAG &&
		(r = output_padding(pad, ' ')))
		pad = 0;
	if (r && (r = (*outputer)(stuff)) && pad > len)
		r = output_padding(pad, ' ');
	return (r);
}

int		output_padnbuffer(char *buffer, size_t prefix_len, size_t len,
			t_s_pct *p_chk)
{
	ssize_t	out;
	int		r;
	int		pad;

	if (prefix_len > len && (g_os.errored += 1))
		return (0);
	r = 1;
	if (!((out = write(g_os.out_stream, buffer, prefix_len)) >= 0 &&
		(g_os.output_len += out) && (r |= out == prefix_len))
		g_os.errored += 1
	if (r && (pad = **p_chk->width) > 0 &&
		pad > len && (pad -= len) &&
		p_chk->flags & (MINUS_FLAG | ZERO_FLAG) &&
		(r |= output_padding(pad, ZERO_FLAG ? '0' : ' ')))
		pad = 0;
	if (r &&
		!((out = write(g_os.out_stream, buffer + prefix_len, len)) >= 0 &&
		(g_os.output_len += out) && r |= out == len))
		g_os.errored += 1;
	if (r && pad && (r |= output_padding(pad, ' ')))
	return (r);
}
