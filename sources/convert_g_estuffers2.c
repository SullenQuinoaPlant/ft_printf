#include "ft_printf_inner.h"

void
	cg_eexponent_sign(
		int pos, void *s)
{
	t_s_ecs	* const stf = (t_s_ecs*)s;
	t_s_so	* const syl = &stf->syls[pos];

	stf->p_exp = my_v_tob(stf->number.pow10, g_dec_syms, stf->exp, e_all);
	syl->len = 1;
	syl->c = *stf->p_exp.c++;
	stf->p_exp.len--;
}

void
	cg_eexponent_pad(
		int pos, void *s)
{
	t_s_ecs	* const stf = (t_s_ecs*)s;
	t_s_so	* const syl = &stf->syls[pos];

	syl->c = '0';
	if (stf->p_exp.len < 2)
		syl->len = 2 - stf->p_exp.len;
	else
		syl->len = 0;
}

void
	cg_eexponent(
		int pos, void *s)
{
	t_s_ecs	* const stf = (t_s_ecs*)s;
	t_s_so	* const syl = stf->syls + pos;

	syl->type = e_sot_apstr_cc;
	syl->cc = stf->p_exp.c;
	syl->len = stf->p_exp.len;
}

#define EXP_DIG 9
#define EXP_GRP 3
void	cg_esetgroups(int pos, void *p)
{
	t_s_so	* const	syls = stf->syls;
	t_s_sgd	ar[G_SYLGRPS] = {
		{&syls[0], 2, 0, 0, 0},
		{&syls[2], 2, AF_DG, AF_DG - 1, AF_DS},
		{&syls[4], 2, AF_DG, 0, AF_DS},
		{&syls[6], 5, AF_DG, -1, AF_DS}};
	int		i;

	(void)pos;
	i = apstr_offset(syls[EXP_DIG].len, ar[EXP_GRP].apstr_grp);
	ar[HIGH_GRP].apstr_pos = i;
	ft_memcpy(stf->syl_grps, ar, sizeof(ar));
}
