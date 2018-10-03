#include "inner.h"

static char	*g_null = "(null)";
static char	*g_nil = "(nil)";

int							output_nil(
	t_s_pct *p)
{
	return(output_string(g_nil, p));
}

int							output_null(
	t_s_pct *p)
{
	return(output_string(g_null, p));
}
