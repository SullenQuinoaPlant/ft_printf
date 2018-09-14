#include "inner.h"

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
		r = utf8_seq(*str++, UTF8_MAX_CHARS, ar);
		output_cc(r, ar);
		len -= r;
	}
	return (len == 0);
}
