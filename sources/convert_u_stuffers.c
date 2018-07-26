#include "ft_printf_inner.h"

void
	cu_prefix(
		int pos, void *p)
{
	t_s_ucs	* const stf = (t_s_ucs*)p;
	t_s_so	* const syl = stf->syls + pos;

	syl->type = e_sot_apstr_c;
	syl->c = '0';
	if (stf->pre > 0 && stf->p_b.len < (size_t)stf->pre)
		syl->len = stf->pre - stf->p_b.len;
}

void
	cu_digits(
		int pos, void *p)
{
	t_s_ucs	* const stf = (t_s_ucs*)p;
	t_s_so	* const syl = stf->syls + pos;

	syl->type = e_sot_apstr_cc;
	syl->cc = stf->p_b.c;
	syl->len = stf->p_b.len;
}
