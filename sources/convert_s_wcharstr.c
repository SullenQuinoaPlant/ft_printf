#include "ft_printf_inner.h"

int
	tsof_wcharstr(
		size_t len, void *p)
{
	wchar_t	*str;
	int		r;
	char	ar[UTF8_MAX_CHARS];

	str = (wchar_t*)p;
	while (len)
	{
		r = as_utf8seq(*str++, UTF8_MAX_CHARS, ar);
		output_cc(r, ar);
		len -= r;
	}
}
