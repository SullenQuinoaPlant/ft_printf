#include "my_utf8.h"

/*To utf-8 format; raw, no checks, can get bigger
** than the standard 4 bytes; will fail should
** wchar_t be more than
** (CHAR_BIT - 1) * (CHAR_BIT - 2) bits large.
*/
int
	as_utf8seq(
		wchar_t val, int char_lim,
		char *put)
{
	int				sz;
	unsigned char	c;
	unsigned char	cs[CHAR_BIT];
	unsigned char	* const pc = cs + CHAR_HBIT;

	sz = 0;
	if (val & ~((c = val) & ~ASCII_MASK))
	{
		while (val && sz < CHAR_HBIT)
		{
			pc[-sz++] = UTF8_01X | (val & ~UTF8_BMASK);
			val >>= UTF8_BITS;
		}
		c = pc[-(sz - 1)];
		if (my_log2(c & ~UTF8_01X) + sz + 2 > CHAR_BIT)
			c = ~0 << (CHAR_BIT - (sz + 1));
		else
			c |= ~0 << (CHAR_BIT - sz--);
	}
	pc[-sz++] = c;
	if ((sz = sz <= char_lim ? sz : 0))
		ft_memcpy(put, pc - sz + 1, sz);
	return (sz);
}

int
	true_utf8seq(
		wchar_t val, char *put)
{
	return (as_utf8seq(val, UTF8_MAX_CHARS, put));
}

size_t
	str_to_utf8(
		wchar_t *str,
		char 	*put,
		size_t 	len)
{
	char	* const lim = put + len - UTF8_MAX_CHARS;
	char	* const save = put;

	if (!(str && *str))
		return (0);
	while (*str && put < lim)
		put += true_utf8seq(*str++, put);
	return (put - save);
}
