#include "inner.h"

void	cf_lowdigits(int pos, void *p)
{
	t_s_fcs	* const stf = (t_s_fcs*)p;
	t_s_so	* const syl = stf->syls + pos;

	syl->type = e_sot_f;
	if (stf->chk->flags & APSTR_FLAG)
		syl->type = e_sot_apstr_f;
	syl->f = tsof_out_eat_tspot;
	syl->arg = &stf->number;
	if (stf->number.pow10 >= -1)
		syl->len = stf->pre;
	else if (-stf->pre >= stf->number.pow10)
		syl->len = stf->pre + stf->number.pow10 + 1;
	else
		syl->len = 0;
}
