#include "h.h"

int		output_padding(int yay_much, char of_this)
{
	int		const much_yay = yay_much;
	int		outputten;

	outputten = 0;
	while (yay_much-- > 0)
		outputten += write(g_os.out_stream, &of_this, 1);
	g_os.output_len += outputten;
	if (outputten < much_yay)
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
