#include "ft_printf_inner.h"

t_s_ps	g_ps;
t_s_os	g_os;

int		ft_printf(const char *format, ...)
{
	int		r;
	va_list	va_p;

	va_start(va_p, format);
	r = -1;
	if (parse_format_string(format) &&
		get_va_args(&va_p) &&
		output_chunks(1, &g_ps))
		r = (int)g_os.output_len;
	free_parse_state_lists(&g_ps);
	va_end(va_p);
	return (r);
}
