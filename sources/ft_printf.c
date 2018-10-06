#include "inner.h"

t_s_ps	g_ps;
t_s_os	g_os;

/*
**they want an int so we give them an int
*/
int									ft_vprintf(
	const char *format,
	va_list *p_va)
{
	int		r;

	r = -1;
	init_parse_state();
	if (parse_format_string(format) &&
		get_va_args(p_va))
	{
		init_output_state(STDOUT_FILENO);
		if (output_chunks(&g_ps))
			r = (int)g_os.output_len;
	}
	free_parse_state_lists(&g_ps);
	return (r);
}

int		ft_printf(
	const char *format,
	...)
{
	int		r;
	va_list	va;

	va_start(va, format);
	r = ft_vprintf(format, &va);
	va_end(va);
	return (r);
}
