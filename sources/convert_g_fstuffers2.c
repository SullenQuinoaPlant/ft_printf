#include "inner.h"

#define SEPARATOR_REL_POS 2
void	cg_flowdigits(int pos, void *p)
{
	t_s_gcs	* const stf = (t_s_gcs*)p;
	t_s_so	* const syl = stf->syls + pos;
	int		skip;

	if (!stf->pre)
		return;
	syl->type = e_sot_apstr_f;
	syl->f = tsof_out_eat_tspot;
	syl->arg = &stf->number;
	if (stf->chk->flags & HASH_FLAG)
		syl->len = stf->pre;
	else
	{
		if ((skip = stf->number.pow10 + 1) <= 0)
			skip = 0;
		stf->pre -= trailing_zeros(stf->number.times, skip, stf->pre);
		if (!(syl->len = stf->pre))
			(syl - SEPARATOR_REL_POS)->len = 0;
	}
}

#define HIGH_DIG 3
#define HIGH_GRP 1
void	cg_fsetgroups(int pos, void *p)
{
	t_s_gcs	* const stf = (t_s_gcs*)p;
	t_s_so	* const	syls = stf->syls;
	t_s_sgd	ar[G_SYLGRPS] = {
		{&syls[0], 2, 0, 0, 0},
		{&syls[2], 3, 3, -1, '\''},
		{&syls[5], 3, 3, 0, '\''},
		{&syls[8], 1, 0, 0, 0}};
	int		i;

	(void)pos;
	i = apstr_offset(syls[HIGH_DIG].len, ar[HIGH_GRP].apstr_grp);
	ar[HIGH_GRP].apstr_pos = i;
	ft_memcpy(stf->syl_grps, ar, sizeof(ar));
}
