#include "ft_printf_inner.h"

static t_stuffer
	g_fstr[D_SYLS] = {
		dummy_stuffer,
		co_sign,
		dummy_stuffer,
		co_prefix,
		co_digits,
		dummy_stuffer};

static int
	set_integer(
		t_s_ocs *stf)
{
	t_s_pct		* const chk = stf->chk;
	t_s_arg		* const arg = chk->vaarg;
	size_t		const dsz = g_et_sz[arg->type];
	uintmax_t	d;

	d = 0;
	ft_memcpy(&d, arg->p_val, dsz);
	stf->p_b = my_uv_tob(d, g_oct_syms, &stf->b, e_all);
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
	stf->group.sz = O_SYLS;
	if (apstr_purge_ornot(stf->chk, stf->syls, O_SYLS))
		noapstr_grp_props(&stf->group);
	else
		apstr_grp_props_offset(AF_DG, AF_DS, &stf->group);
}

void		convert_o(t_s_pct *chk)
{
	int			pad_indexes[e_pp_sz] = {0};
	t_s_dcs		stf;
	int			r;
	
	stf.chk = chk;
	init_syls(e_sot_c, O_SYLS, stf.syls);
	r = set_integer(&stf);
	r |= set_precision(&stf);
	if (r)
	{
		call_tstuffers(g_fstr, &stf, pad_indexes);
		set_group(&stf);
		set_pad_syl(chk, pad_indexes, &stf.group, 1);
		out_syl_groups(&stf.group, 1);
	}
}
