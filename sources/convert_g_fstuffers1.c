#include "ft_printf_inner.h"

void	cg_fsign(int pos, void *p)
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

void	cg_fhighdigits(int pos, void *p)
{
	t_s_fcs	* const stf = (t_s_fcs*)p;
	t_s_so	* const syl = stf->syls + pos;
	int		i;

	syl->type = e_sot_apstr_f;
	syl->f = tsof_out_eat_tspot;
	syl->arg = &stf->number;
	if ((i = stf->number.pow10 + 1) <= 0)
		syl->len = 0;
	else
	{
		syl->len = (size_t)i;
		stf->pre -= i;
	}
}

void	cg_fpowerzero(int pos, void *p)
{
	t_s_fcs	* const stf = (t_s_fcs*)p;
	t_s_so	* const syl = stf->syls + pos;

	syl->type = e_sot_apstr_c;
	if ((syl->len = stf->number.pow10 < 0 ? 1 : 0))
	{
		stf->pre--;
		if (!stf->pre &&
			stf->number.pow10 == -1 &&
			stf->number.times > 5.0)
			syl->c = '1';
		else
			syl->c = '0';
	}
}

void	cg_fseparator(int pos, void *p)
{
	t_s_fcs	* const stf = (t_s_fcs*)p;
	t_s_so	* const syl = stf->syls + pos;

	syl->type = e_sot_c;
	syl->c = '.';
	syl->len = stf->chk->flags & HASH_FLAG ? 1 : 0;
	if (stf->pre && -stf->pre <= stf->number.pow10)
		syl->len = 1;
	else
		stf->pre = 0;
}

void	cg_fzeros(int pos, void *p)
{
	t_s_fcs	* const stf = (t_s_fcs*)p;
	t_s_so	* const syl = stf->syls + pos;

	syl->type = e_sot_apstr_c;
	syl->c = '0';
	if (stf->number.pow10 < -1 && stf->pre)
	{
		syl->len = -(stf->number.pow10 + 1);
		stf->pre -= syl->len;
	}
}
