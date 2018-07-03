#include "ft_printf_inner.h"

void
	ce_sign(
		int pos, void *s)
{
	t_s_ecs	* const stf = (t_s_ecs*)s;

	stf->syls[pos].len = 1;
	if (stf->number.times < 0)
		stf->syls[pos].c = '-';
	else if (stf->chk->flags && PLUS_FLAG)
		stf->syls[pos].c = '+';
	else if (stf->chk->flags && SPACE_FLAG)
		stf->syls[pos].c = ' ';
	else
		stf->syls[pos].len = 0;
}

void
	ce_zero(
		int pos, void *s)
{
	t_s_ecs	* const stf = (t_s_ecs*)s;
	t_s_So	* const syl = &stf->syls[pos];

	syl->len = 1;
	syl->type = e_sot_apstr_f;
	syl->f = &tsof_out_eat_tspot;
	syl->arg = &tsf->number;
}

void
	ce_separator(
		int pos, void *s)
{
	t_s_ecs	* const stf = (t_s_ecs*)s;

	stf->syls[pos].c = '.';
	stf->syls[pos].len = 1;
	if (!(stf->pre || stf->chk->flags & HASH_FLAG))
		stf->syls[pos].len = 0;
}

void
	ce_lowdigits(
		int pos, void *s)
{
	t_s_ecs	* const stf = (t_s_ecs*)s;
	t_s_So	* const syl = &stf->syls[pos];

	syl->len = stf->pre;
	syl->type = e_sot_apstr_f;
	syl->f = &tsof_out_eat_tspot;
	syl->arg = &tsf->number;
}

void
	ce_to_the_power(
		int pos, void *s)
{
	t_s_ecs	* const stf = (t_s_ecs*)s;
	t_s_so	* const syl = &stf->syls[pos];

	syl->len = 1;
	if (stf->chk->flags & BIGCS_FLAG)
		syl->c = 'E';
	else
		syl->c = 'e';
}
