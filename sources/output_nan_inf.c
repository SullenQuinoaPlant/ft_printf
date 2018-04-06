#include "h.h"

static char	*g_nan = "nan";
static char	*g_bignan = "NAN*";
static char *g_inf = "inf";
static char *g_biginf = "INF";

int		is_nan_inf(t_u_d t)
{
(void)g_nan;
(void)g_bignan;
(void)g_inf;
(void)g_biginf;
	t_u_d const	ref = (t_u_d){.parts = {.exponent = ~0}};

	if (t.parts.exponent == ref.parts.exponent)
		return (1);
	return (0);
}
