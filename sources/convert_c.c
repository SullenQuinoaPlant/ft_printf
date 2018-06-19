#include "ft_printf_inner.h"

static void
	filter_flags(t_s_pct *chk)
{
	chk->flags &= MINUS_FLAG;
}

void		convert_c(t_s_pct *p_chk)
{
}
