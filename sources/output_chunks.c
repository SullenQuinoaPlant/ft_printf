#include "ft_printf_inner.h"

int			gos_update(ssize_t writ, size_t expected)
{
	if (writ > 0)
		g_os.output_len += writ;
	if (writ < 0 || writ < expected)
	{
		g_os.errored++;
		return (0);
	}
	return (1);
}

static void	output_chunk(t_s_cw *p_cw)
{
	t_e_cts 	type;
	void const	*p_chk;

	if (p_cw && (type = p_cw->type) && (p_chk = p_cw->p_chk))
	{
		if (type == e_txt_c)
			output_txt_chk(p_chk);
		else if (type == e_char_c)
			output_char_chk(p_chk);
		else if (type == e_pct_c)
			output_pct_chk(p_chk);
	}
	else
		g_os.errored++;
}

static void	init_g_os(int fd)
{
	g_os.out_str_len = 0;
	g_os.out_stream = fd;
	g_os.errored = 0;
}

int			output_chunks(int fd, t_s_ps *p_parsed)
{
	t_list	*p_link;

	init_g_os(fd);
	p_link = &p_parsed->chunks;
	while((p_link = p_link->next) && !g_os.errored)
		output_chunk(p_link->content);
	return (g_os.errored ? 0 : 1);
}
