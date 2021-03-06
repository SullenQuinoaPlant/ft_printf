#include "inner.h"

void	output_char_chk(t_s_char const * const chk)
{
	ssize_t	i;

	i = write(g_os.fd, &chk->c, 1);
	if (i < 0)
		g_os.errored++;
	else
		g_os.output_len += 1;
}

void	output_txt_chk(t_s_txt const * const chk)
{
	ssize_t	i;

	i = write(g_os.fd, chk->strt, chk->len);
	if (i < 0)
		g_os.errored++;
	else
		g_os.output_len += (size_t)i;
}
