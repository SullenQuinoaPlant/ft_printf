#include "ft_printf_inner.h"

static t_s_ctl *
	ctl_chk_init()
{
	t_s_ctl	*ctl_chk;

	if ((ctl_chk = malloc(sizeof(t_s_ctl))))
		*ctl_chk = (t_s_ctl){0, 0};
	return (ctl_chk);
}

static 
t_parser const
	g_f_str[] = {
		percent_control_fd,
		0};

char const *
	parse_convert(
		char const *in)
{
	char const	* const save = in;
	t_s_cw 		* const cw = g_ps.chunks.tail->content;
	t_s_ctl		*chk;

	if (*in++ != '{')
		return (save);
	if ((chk = ctl_chk_init()))
	{
		*cw = (t_s_cw){e_ctl_chk, chk};
		in = attempt_all(in, g_f_str);
		if (!(*chk->foo && *in++ == '}'))
			in = save;
	}
	else
		g_ps.errored++;
	return (in);
}

t_s_ctl *
	get_tsctl()
{
	t_s_cw	*cw;

	cw = g_ps.chunks.tail->content;
	return (cw->chk);
}
