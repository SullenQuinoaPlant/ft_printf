#include "h.h"

char		*parse_percent(char const *in)
{
	char	*(* const f_str[])(char const *) = {
			percent_char,
			percent_conversion,
			0};
	t_list	*p_wrap;

	if (*in == '%')
	{
		if ((p_wrap = ft_lstnew(&(t_s_cw){e_no_c_type, 0}, sizeof(t_e_cts))))
		{
			my_lstappend(&g_ps.chunks.content, p_wrap);
			in++;
			in = until_progress(in, f_str);
		}
		else
			g_ps.errored++;
	}
	return (in);
}
