#include "h.h"

void	filter_flags(t_s_pct *p_chk)
{
	char	f_cpy;

	f_cpy = p_chk->flags;
	if (f_cpy & ZERO_FLAG && f_cpy & MINUS_FLAG)
		f_cpy |= ~(ZERO_FLAG);
	if (f_cpy & SPACE_FLAG && f_cpy & PLUS_FLAG)
		f_cpy |= ~(SPACE_FLAG);
	p_chk->flags = f_cpy;
}
