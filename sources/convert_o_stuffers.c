#include "ft_printf_inner.h"

void
	co_sign(
		int pos, void *p)
{
	t_s_dcs	* const stf = (t_s_dcs*)p;
	t_s_so	* const syl = stf->syls + pos;
	char	const flags = stf->chk->flags;

	syl->len = 1;
	if (flags & SPACE_FLAG)
		syl->c = ' ';
	else if (flags & PLUS_FLAG)
		syl->c = '+';
	else
		syl->len = 0;
}

void
	co_prefix(
		int pos, void *p)
{
	t_s_dcs	* const stf = (t_s_dcs*)p;
	t_s_so	* const syl = stf->syls + pos;

	syl->type = e_sot_apstr_c;
	syl->c = '0';
	if (stf->pre > 0 && stf->p_b.len < (size_t)stf->pre)
		syl->len = stf->pre - stf->p_b.len;
}

void
	co_digits(
		int pos, void *p)
{
	t_s_dcs	* const stf = (t_s_dcs*)p;
	t_s_so	* const syl = stf->syls + pos;

	syl->type = e_sot_apstr_cc;
	syl->cc = stf->p_b.c;
	syl->len = stf->p_b.len;
}
