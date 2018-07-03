#include "ft_printf_inner.h"

void
	ce_exponent_sign(
		int pos, void *s)
{
	t_s_ecs	* const stf = (t_s_ecs*)s;
	t_s_so	* const syl = &stf->syls[pos];

	syl->len = 1;
	syl->c = *stf->p_exp.c++;
}

void
	ce_exponent_pad(
		int pos, void *s)
{
	t_s_ecs	* const stf = (t_s_ecs*)s;
	t_s_so	* const syl = &stf->syls[pos];

	syl->c = '0';
	if (stf->p_exp.len < 2)
		syl->len = 2 - stf->p_exp.len;
	else
		syl->len = 0;
}

void
	ce_exponent(
		int pos, void *s)
{
	t_s_ecs	* const stf = (t_s_ecs*)s;
	t_s_so	* const syl = stf->syls[pos];

	syl->type = e_sot_apstr_cc;
	syl->cc = stf->p_exp.c;
}
