#include "inner.h"

t_s_ps	g_ps;
t_s_os	g_os;

/*
**they want an int so we give them an int
*/
int		ft_vprintf(const char *format, va_list va_p)
{
	int		r;

	r = -1;
	init_parse_state();
	if (parse_format_string(format) &&
		get_va_args((va_list*)&va_p))
	{
		init_output_state(STDOUT_FILENO);
		if (output_chunks(&g_ps))
			r = (int)g_os.output_len;
	}
	free_parse_state_lists(&g_ps);
	return (r);
}

int		ft_printf(const char *format, ...)
{
	int		r;
	va_list	va_p;

	va_start(va_p, format);
	r = ft_vprintf(format, va_p);
	va_end(va_p);
	return (r);
}
