#include "ft_printf.h"

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
	return (yay_much == 0);
}

void	output_padnstuff(size_t len, t_s_pct *p_chk,
					t_outputter f[], void *stuff)
{
	unsigned int	flags;
	int				r;
	int				pad;

	flags = p_chk->flags;
	pad = **p_chk->width > 0 && pad > len ? pad - len : 0;
	if (pad && flags & MINUS_FLAG && !(pad = 0))
		if (!(r = output_padding(pad, ' ')))
			return;
	if (!(r = f[e_oi_prefix](p_chk, stuff)))
		return;
	if (pad && flags & ZERO_FLAG && !(pad = 0))
		if (!(r = output_padding(pad, ' ')))
			return;
	if (!(r = f[e_oi_body](p_chk, stuff)))
		return;
	if (pad)
		output_padding(pad, ' ');
}

void	output_padnbuffer(char *buffer, size_t prefix_len,
				size_t len, t_s_pct *p_chk)
{
	ssize_t			out;
	unsigned int	flags;
	int				r;
	int				pad;

	flags = p_chk->flags;
	pad = **p_chk->width > 0 && pad > len ? pad - len : 0;
	if (pad && flags & MINUS_FLAG)
		pad = (r = output_padding(pad, ' ')) ? pad : 0;
	if (!r)
		return;
	out = write(g_os.out_stream, buffer, prefix_len);
	if (!(r = register_status(out, prefix_len)))
		return;
	if (pad && flags & ZERO_FLAG)
		pad = (r = output_padding(pad, '0')) ? pad : 0;
	if (!r)
		return;
	out = write(g_os.out_stream, buffer + prefix_len, len);
	if(!(r = register_status(out, len)))
		return;
	if (pad)
		r = output_padding(pad, ' ');
}
