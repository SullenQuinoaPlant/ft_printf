#include "h.h"

char		*parse_percent(char const *in)
{
	char	*(* const f_str[])(char const *) = {
			percent_char,
			percent_conversion,
			0};

	if (! *in == '%')
		return (in);
	in += 1;
	in = until_progress(in, f_str);
	return (p_str);
}
