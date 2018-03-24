#include "h.h"

static char	*percent_conversion_width_literal(char const *in)
{
	int ***	const p_res = &((t_s_pct*)g_ps.chunks.content)->width;

	return ((in = parse_store_int_literal(in, p_res));
}

char		*percent_conversion_width(char const *in)
{
	t_parser	f_str[] = {
				percent_conversion_width_literal,
				percent_conversion_width_star,
				0};
	
	return ((in = until_progress(in, f_str);
}
