#include "h.h"

char		*parse_percent(char const *in)
{
	char	*(* const f_str[])(char const *) = {
			percent_char,
			percent_conversion,
			parse_text,
			0};
	char	*p_str;
	int		i;

	if (! *in == '%')
		return (in);
	p_str = ++in;
	i = -1;
	while (f_str[++i] && p_str == in)
		p_str = f_str[i](p_str);
	return (p_str);
}
