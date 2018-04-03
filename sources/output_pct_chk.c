#include "h.h"

void	(*f_ar[e_types_sz])(

void	output_pct_chk(t_s_pct *chk)
{
	f_ar[chk->convertee->type](chk);
}
