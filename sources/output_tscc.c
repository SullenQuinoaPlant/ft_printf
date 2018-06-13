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

int		output_raw(char *b, size_t len)
{
	size_t	len1;
	size_t	len2;

	if (!len)
		return (1);
	len1 = len / 2;
	len2 = len & 0x1 ? len1 + 1 : len1;
	if (gos_update(write(g_os.fd, b, len1), len1) &&
		gos_update(write(g_os.fd, b + len1, len2), len2))
		return (1);
	return (0);
}

int		output_tscc(t_s_cc this)
{
	return (output_raw(this.c, this.len));
}
