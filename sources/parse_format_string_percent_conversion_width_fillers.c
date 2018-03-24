#include "h.h"

char	*percent_conversion_width_literal(char const *in)
{
	int **	const p_res = &((t_s_pct*)g_ps.chunks.content)->width;

	return ((in = parse_store_int_literal(in, p_res));
}
