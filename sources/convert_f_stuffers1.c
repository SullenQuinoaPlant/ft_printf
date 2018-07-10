#include "ft_printf_inner.h"
void	cf_sign(int syl, void *p)
{
	t_s_fcs	* const stf = (t_s_fcs*)p;
	t_s_so	* const syl = stf->syls + syl;

	syl->type = e_sot_c;
	syl->len = 1;
	if (stf->number.times < 0)
		syl->c = '-';
	else if (stf->chk->flags & SPACE_FLAG)
		syl->c = ' ';
	else if (stf->chk->flags & PLUS_FLAG)
		syl->c = '+';
	else
		syl->len = 0;
}

void	cf_highdigits(int syl, void *p)
{
	t_s_fcs	* const stf = (t_s_fcs*)p;
	t_s_so	* const syl = stf->syls + syl;

	syl->type = e_sot_f;
	if (stf->chk->flags & APSTR_FLAG)
		syl->type = e_sot_apstr_f;
	syl->len = 0;
	if (stf->number.pow10 > 0)
		syl->len = (size_t)stf->number.pow10 + 1;
}

void	cf_separator(int syl, void *p)
{
	t_s_fcs	* const stf = (t_s_fcs*)p;
	t_s_so	* const syl = stf->syls + syl;

	syl->type = e_sot_c;
	syl->c = '.';
	syl->len = 0;
	if (stf->pre || stf->chk->flags & HASH_FLAG)
		syl->len = 1;
}

void	cf_lowdigits(int syl, void *p)
{
	t_s_fcs	* const stf = (t_s_fcs*)p;
	t_s_so	* const syl = stf->syls + syl;

	syl->type = e_sot_f;
	if (stf->chk->flags & APSTR_FLAG)
		syl->type = e_sot_apstr_f;
	syl->len = stf->precision;
}
