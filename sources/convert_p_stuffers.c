#include "ft_printf_inner.h"

void
	cp_sign(
		int pos, void *p)
{
	t_s_pcs	* const stf = (t_s_pcs*)p;
	char	const flags = stf->chk->flags;
	t_s_so	* const syl = stf->syls + pos;

	syl->len = 1;
	if (flags & SPACE_FLAG)
		syl->c = ' ';
	else if (flags & PLUS_FLAG)
		syl->c = '+';
	else
		syl->len = 0;
}

void
	cp_hashfix(
		int pos, void *p)
{
	t_s_pcs	* const stf = (t_s_pcs*)p;
	t_s_so	* const syl = stf->syls + pos;

	syl->cc = "0x";
	syl->len = ft_strlen(syl->cc);
	syl->type = e_sot_cc;
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
