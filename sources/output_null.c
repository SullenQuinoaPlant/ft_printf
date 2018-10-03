#include "inner.h"

static char	*g_null = "(null)";

static int	output_null(t_s_pct *p)
{
	char	*s;
	size_t	l;
	int		r;

	s = g_null;
	l = ft_strlen(s);
	r = output_padnbuffer(s, (size_t[e_oi_sz]){0, l}, p);
	return (r);
}
