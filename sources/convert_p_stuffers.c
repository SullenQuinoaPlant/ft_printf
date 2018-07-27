#include "ft_printf_inner.h"

void
	cp_hashfix(
		int pos, void *p)
{
	t_s_pcs	* const stf = (t_s_pcs*)p;
	t_s_so	* const syl = stf->syls + pos;
	char	* str;

	syl->len = sizeof(stf->hashfix); 
	syl->type = e_sot_cc;
	syl->cc = stf->hashfix;
	str = "+0x";
	if (stf->chk->flags & SPACE_FLAG)
		str = " 0x";
	ft_memcpy(stf->hashfix, str, syl->len);
}

void
	cp_prefix(
		int pos, void *p)
{
	t_s_pcs	* const stf = (t_s_pcs*)p;
	t_s_so	* const syl = stf->syls + pos;

	syl->type = e_sot_apstr_c;
	syl->c = '0';
	if (stf->pre > 0 && stf->p_b.len < (size_t)stf->pre)
		syl->len = stf->pre - stf->p_b.len;
}

void
	cp_digits(
		int pos, void *p)
{
	t_s_pcs	* const stf = (t_s_pcs*)p;
	t_s_so	* const syl = stf->syls + pos;

	syl->type = e_sot_apstr_cc;
	syl->cc = stf->p_b.c;
	syl->len = stf->p_b.len;
}
