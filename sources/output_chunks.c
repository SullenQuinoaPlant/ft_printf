#include "ft_printf_inner.h"

static void	output_chunk(t_s_cw *p_cw)
{
	t_e_cts	type;
	void 	*chk;

	if (p_cw && (type = p_cw->type) && (chk = p_cw->chk))
	{
		if (type == e_txt_c)
			output_txt_chk(chk);
		else if (type == e_char_c)
			output_char_chk(chk);
		else if (type == e_pct_c)
			output_pct_chk(chk);
	}
	else
		g_os.errored++;
}

static void	init_g_os(int fd)
{
	g_os.output_len = 0;
	g_os.fd = fd;
	g_os.errored = 0;
}

int			output_chunks(int fd, t_s_ps *p_parsed)
{
	t_list	*p_link;

	init_g_os(fd);
	p_link = &p_parsed->chunks.head;
	while((p_link = p_link->next) && !g_os.errored)
		output_chunk(p_link->content);
	return (g_os.errored ? 0 : 1);
}
