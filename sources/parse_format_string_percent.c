#include "ft_printf_inner.h"

char		*parse_percent(char const *in)
{
	char	*(* const f_str[])(char const *) = {
			percent_char,
			percent_convert,
			0};
	t_list	*p;

	if (*in == '%')
	{
		in++;
		if ((p = ft_lstnew(&(t_s_cw){e_no_chk, 0}, sizeof(t_s_cw))))
		{
			my_lstappend(&g_ps.chunks.tail, p);
			in = until_progress(in, f_str);
		}
		else
			g_ps.errored++;
	}
	return (in);
}
