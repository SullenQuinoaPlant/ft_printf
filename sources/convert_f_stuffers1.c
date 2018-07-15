#include "ft_printf_inner.h"

void	cf_sign(int pos, void *p)
{
	t_s_fcs	* const stf = (t_s_fcs*)p;
	t_s_so	* const syl = stf->syls + pos;

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

void	cf_highdigits(int pos, void *p)
{
	t_s_fcs	* const stf = (t_s_fcs*)p;
	t_s_so	* const syl = stf->syls + pos;

	syl->type = e_sot_f;
	if (stf->chk->flags & APSTR_FLAG)
		syl->type = e_sot_apstr_f;
	syl->f = tsof_out_eat_tspot;
	syl->arg = &stf->number;
	if (stf->number.pow10 < 0)
		syl->len = 0;
	else
		syl->len = (size_t)stf->number.pow10 + 1;
}

void	cf_powerzero(int pos, void *p)
{
	t_s_fcs	* const stf = (t_s_fcs*)p;
	t_s_so	* const syl = stf->syls + pos;

	syl->type = e_sot_c;
	if (stf->chk->flags & APSTR_FLAG)
		syl->type = e_sot_apstr_c;
	if ((syl->len = stf->number.pow10 < 0 ? 1 : 0))
	{
		if (!stf->pre &&
			stf->number.pow10 == -1 &&
			stf->number.times > 5.0)
			syl->c = '1';
		else
			syl->c = '0';
	}
}

void	cf_separator(int pos, void *p)
{
	t_s_fcs	* const stf = (t_s_fcs*)p;
	t_s_so	* const syl = stf->syls + pos;

	syl->type = e_sot_c;
	syl->c = '.';
	syl->len = 0;
	if (stf->pre || stf->chk->flags & HASH_FLAG)
		syl->len = 1;
}

void	cf_zeros(int pos, void *p)
{
	t_s_fcs	* const stf = (t_s_fcs*)p;
	t_s_so	* const syl = stf->syls + pos;

	syl->type = e_sot_c;
	syl->c = '0';
	if (stf->chk->flags & APSTR_FLAG)
		syl->type = e_sot_apstr_c;
	if (stf->number.pow10 < -1)
	{
		if (stf->number.pow10 < -stf->pre)
			syl->len = stf->pre;
		else
			syl->len = -(stf->number.pow10 + 1);
	}
	else
		syl->len = 0;
}
