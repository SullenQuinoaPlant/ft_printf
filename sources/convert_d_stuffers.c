#include "inner.h"

void
	cd_sign(
		int pos, void *p)
{
	t_s_dcs	* const stf = (t_s_dcs*)p;
	t_s_so	* const syl = stf->syls + pos;

	syl->len = 1;
	if ((syl->c = *stf->p_b.c) == '+')
	{
		if (stf->chk->flags & SPACE_FLAG)
			syl->c = ' ';
		else if (!(stf->chk->flags & PLUS_FLAG))
			syl->len = 0;
	}
}

#define SIGN 1
void
	cd_prefix(
		int pos, void *p)
{
	t_s_dcs	* const stf = (t_s_dcs*)p;
	t_s_so	* const syl = stf->syls + pos;

	if (stf->chk->flags & APSTR_FLAG)
		syl->type = e_sot_apstr_c;
	syl->c = '0';
	if (stf->pre > 0 &&
		(stf->p_b.len - SIGN) < (size_t)stf->pre)
		syl->len = stf->pre - (stf->p_b.len - SIGN);
}

void
	cd_digits(
		int pos, void *p)
{
	t_s_dcs	* const stf = (t_s_dcs*)p;
	t_s_so	* const syl = stf->syls + pos;

	syl->type = e_sot_cc;
	if (stf->chk->flags & APSTR_FLAG)
		syl->type = e_sot_apstr_cc;
	if (*(syl->cc = stf->p_b.c + SIGN) != '0' || stf->pre)
		syl->len = stf->p_b.len - SIGN;
}
