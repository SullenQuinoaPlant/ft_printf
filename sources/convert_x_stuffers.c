#include "ft_printf_inner.h"

void
	cx_hashfix(
		int pos, void *p)
{
	t_s_xcs	* const stf = (t_s_xcs*)p;
	t_s_so	* const syl = stf->syls + pos;

	if (!(stf->chk->flags & HASH_FLAG) ||
		*stf->p_b.c == '0')
		return;
	syl->len = sizeof(stf->hashfix); 
	syl->type = e_sot_cc;
	ft_memcpy(stf->hashfix, "0x", syl->len);
	syl->cc = stf->hashfix;
}

void
	cx_prefix(
		int pos, void *p)
{
	t_s_xcs	* const stf = (t_s_xcs*)p;
	t_s_so	* const syl = stf->syls + pos;

	syl->type = e_sot_apstr_c;
	syl->c = '0';
	if (stf->pre > 0 && stf->p_b.len < (size_t)stf->pre)
		syl->len = stf->pre - stf->p_b.len;
}

void
	cx_digits(
		int pos, void *p)
{
	t_s_xcs	* const stf = (t_s_xcs*)p;
	t_s_so	* const syl = stf->syls + pos;

	syl->type = e_sot_apstr_cc;
	syl->cc = stf->p_b.c;
	syl->len = stf->p_b.len;
}
