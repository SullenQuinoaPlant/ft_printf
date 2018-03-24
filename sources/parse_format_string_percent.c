#include "h.h"

char		*parse_percent(char const *in)
{
	char	*(* const f_str[])(char const *) = {
			percent_char,
			percent_conversion,
			0};

	if (*in == '%')
	{
		in++;
		in = until_progress(in, f_str);
	}
	return (in);
}
