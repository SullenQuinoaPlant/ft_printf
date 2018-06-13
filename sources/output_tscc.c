include "ft_printf_inner.h"

int		gos_update(ssize_t writ, size_t expected)
{
	if (writ > 0)
		g_os.output_len += writ;
	if (writ < 0 || (size_t)writ < expected)
	{
		g_os.errored++;
		return (0);
	}
	return (1);
}

int		output(t_s_cc this)
{
	int		r;
	ssize_t	out;

	if (!this.len)
		return (1);
	out = write(g_os.fd, this.c, this.len);
	r = gos_update(out, this.len);
	return (r);
}
