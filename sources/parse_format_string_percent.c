#include "ft_printf_inner.h"

static char const *
	(* const g_f_str[])(char const *) = {
		percent_char,
		parse_convert,
		0};

char const	*parse_percent(char const *in)
{
	size_t const	sz = sizeof(t_s_cw);
	t_list	*p;

	if (*in != '%')
		return (in);
	in++;
	if ((p = ft_lstnew(&(t_s_cw){e_no_chk, 0}, sz)))
	{
		my_lstappend(&g_ps.chunks.tail, p);
		in = until_progress(in, g_f_str);
	}
	else
		g_ps.errored++;
	return (in);
}
