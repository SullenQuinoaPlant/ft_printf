#include "h.h"

int		output_padding(size_t yay_much, char of_this)
{
	size_t	much_yay;

	much_yay = yay_much;
	while (yay_much--)
		if (write(g_os.out_stream, &of_this, 1) != 1)
		{
			g_os.errored++;
			break;
		}
	g_os.output_len += much_yay - ++yay_much;
	return (much_yay == yay_much);
}

/*unused function*/
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

static int	register_status(ssize_t written, size_t should_have_written)
{
	if (written > 0)
		g_os.output_len += written;
	if (written < 0 || written < should_have_written)
	{
		g_os.errored++;
		return (0);
	}
	return (1);
}

int			output_padnbuffer(char *buffer, size_t prefix_len,
				size_t len, t_s_pct *p_chk)
{
	ssize_t			out;
	unsigned int	flags;
	int				r;
	int				pad;

	out = write(g_os.out_stream, buffer, prefix_len);
	if (!(r = register_status(out, prefix_len)))
		return (0);
	flags = p_chk->flags;
	pad = **p_chk->width > 0 && pad > len ? pad - len : 0;
	if (pad && flags & (MINUS_FLAG | ZERO_FLAG))
	{
		if (!(r = output_padding(pad, flags & ZERO_FLAG ? '0' : ' ')))
			return (0);
		pad = 0;
	}
	out = write(g_os.out_stream, buffer + prefix_len, len);
	if(!(r = register_status(out, len)))
		return (0);
	if (pad)
		r = output_padding(pad, ' ');
	return (r);
}
