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

	pad = **p_chk->width;
	if (pad > 0 && (size_t)pad > len)
		pad -= len;
	else
		pad = 0;
	return (pad);
}

void		output_padnstuff(
	size_t len, t_s_pct *p_chk,
	t_outputter const f[], void *stuff)
{
	unsigned int	flags;
	int				r;
	int				pad;

	flags = p_chk->flags;
	pad = get_padlen(p_chk, len);
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

int			output_padnbuffer(
	char *buffer, size_t prefix_len,
	size_t len, t_s_pct *p_chk)
{
	ssize_t			out;
	unsigned int	flags;
	int				r;
	int				pad;

	flags = p_chk->flags;
	pad = get_padlen(p_chk, prefix_len + len);
	r = 1;
	if (pad && flags & MINUS_FLAG)
		pad = (r = output_padding(pad, ' ')) ? pad : 0;
	if (!r)
		return (0);
	out = write(g_os.fd, buffer, prefix_len);
	r = gos_update(out, prefix_len);
	if (r && pad && flags & ZERO_FLAG)
		pad = (r = output_padding(pad, '0')) ? pad : 0;
	if (!r)
		return (0);
	out = write(g_os.fd, buffer + prefix_len, len);
	r = gos_update(out, len);
	if (pad && r)
		r = output_padding(pad, ' ');
	return (r);
}
