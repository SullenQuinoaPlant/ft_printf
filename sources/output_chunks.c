#include "h.h"

t_s_os	g_os;

static void	output_txt_chk(t_s_txt const * const chk)
{
	ssize_t	i;

	i = write(g_os.out_stream, chk->strt, chk->len);
	if (i < 0)
		g_os.errored++;
	else
		g_os.out_str_len += (size_t)i;
}

static void	output_char_chk(t_s_char const * const chk)
{
	ssize_t	i;

	i = write(g_os.out_stream, chk->c, 1);
	if (i < 0)
		g_os.errored++;
	else
		g_os.out_str_len += 1;
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

static void	refresh_g_os(int fd)
{
	g_os.out_str_len = 0;
	g_os.out_stream = fd;
	g_os.errored = 0;
}

ssize_t	output_chunks(int fd, t_s_ps *p_parsed)
{
	t_list	*p_link;

	refresh_g_os(fd);
	p_link = &p_parsed->chunks;
	while((p_link = p_link->next))
		output_chunk(p_link->content);
	return (g_os.errored ? -1 : g_os.out_str_len);
}
