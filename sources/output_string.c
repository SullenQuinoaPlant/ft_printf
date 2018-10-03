#include "inner.h"

int							output_string(
	char const *str,
	t_s_pct *p)
{
	size_t	l;
	int		r;

	p->flags &= ~ZERO_FLAG;
	l = ft_strlen(str);
	r = output_padnbuffer(str, (size_t[e_oi_sz]){0, l}, p);
	return (r);
}
