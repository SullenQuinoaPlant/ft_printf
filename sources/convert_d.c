#include "ft_printf_inner.h"

static t_stuffer
	g_fstr[D_SYLS] = {
		dummy_stuffer,
		cd_sign,
		dummy_stuffer,
		cd_prefix,
		cd_digits,
		dummy_stuffer};

static int
	set_integer(
		t_s_dcs *stf)
{
	t_s_pct		* const chk = stf->chk;
	t_s_arg		* const arg = chk->vaarg;
	size_t		const dsz = g_etsz[arg->type];
	intmax_t	d;

	d = 0;
	ft_memcpy(&d, arg->p_val, dsz);
	if (d & (((intmax_t)1) << ((CHAR_BIT * dsz) - 1)))
		d |= ~((((intmax_t)1) << (CHAR_BIT * dsz)) - 1);
	stf->p_b = my_v_tob(d, g_dec_syms, &stf->b, e_all);
	return (d ? 1 : 0);
}

static int
	set_precision(
		t_s_dcs *stf)
{
	t_s_pct		* const chk = stf->chk;

	return ((stf->pre = chk->precision ? **chk->precision : -1));
}

static void
	set_group(
		t_s_dcs *stf)
{
	stf->group.first = stf->syls;
	stf->group.sz = D_SYLS;
	if (is_apstr(stf->chk))
		apstr_set_offset_grp(&stf->group, AF_DG, AF_DS);
	else
		apstr_set_nogrp(&stf->group);
}

void		convert_d(t_s_pct *chk)
{
	int			pad_indexes[e_pp_sz] = {0};
	t_s_dcs		stf;
	int			r;
	
	stf.chk = chk;
	init_syls(e_sot_c, D_SYLS, stf.syls);
	r = set_integer(&stf);
	r |= set_precision(&stf);
	if (r)
	{
		stuff_stuff(g_fstr, &stf, pad_indexes);
		purge_apstr(chk, stf.syls, D_SYLS);
		set_group(&stf);
		set_pad_syl(chk, pad_indexes, &stf.group, 1);
		out_syl_groups(&stf.group, 1);
	}
}
