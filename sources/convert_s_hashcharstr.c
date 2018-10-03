#include "inner.h"

#define ASCII_PRINTABLE ' '
int					tsof_hash_charstr(
	size_t len,
	void *p)
{
	char	*str;
	char	c;
	int		r;

	str = (char*)p;
	while (--len)
	{
		c = *str++;
		c = c < ASCII_PRINTABLE ? c + ASCII_PRINTABLE : c;
		r = output_c(1, c);
	}
	return (r);
}
