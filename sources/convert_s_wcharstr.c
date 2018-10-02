#include "inner.h"

int					tsof_wcharstr(
	size_t len,
	void *p)
{
	wchar_t	*str;
	int		r;
	char	ar[UTF8_MAX_CHARS];

	str = (wchar_t*)p;
	while (len)
	{
		r = utf8_trueseq(*str++, ar);
		output_cc(r, ar);
		len -= r;
	}
	return (len == 0);
}

#define ASCII_PRINTABLE ' '
int					tsof_hash_wcharstr(
	size_t len,
	void *p)
{
	wchar_t	*str;
	wchar_t	wc;
	int		r;
	char	ar[UTF8_MAX_CHARS];

	str = (wchar_t*)p;
	while (len)
	{
		wc = *str++;
		wc = wc < ASCII_PRINTABLE ? wc + ASCII_PRINTABLE : wc;
		r = utf8_trueseq(wc, ar);
		output_cc(r, ar);
		len -= r;
	}
	return (len == 0);
}
