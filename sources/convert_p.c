#include "ft_printf_inner.h"

void		convert_p(t_s_pct *chk)
{
	chk->flags |= HASH_FLAG;
	convert_x(chk);
}
