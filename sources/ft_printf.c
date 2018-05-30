#include "ft_printf_inner.h"

int		ft_printf(const char *format, ...)
{
	int		r;
	va_list	va_p;

	va_start(va_p, format);
	if (parse_format_string(format) &&
		
	va_end(va_p);
}
