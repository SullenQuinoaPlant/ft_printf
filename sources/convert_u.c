#include "inner.h"

static t_stuffer
	g_fstr[D_SYLS + 1] = {
		dummy_stuffer,
		dummy_stuffer,
		cu_prefix,
		cu_digits,
		dummy_stuffer,
		0};

static int
	set_uinteger(
		t_s_ucs *stf)
{
	t_s_pct		* const chk = stf->chk;
	t_s_arg		* const arg = chk->vaarg;
	uintmax_t	d;

	d = 0;
	ft_memcpy(&d, arg->p_val, g_et_sz[arg->type]);
	stf->p_b = vtb_uv_tscc(d, VTB_DEC_SYMS, &stf->b);
	return (d ? 1 : 0);
}

static int
	set_precision(
		t_s_ucs *stf)
{
	t_s_pct		* const chk = stf->chk;

	return ((stf->pre = chk->precision ? **chk->precision : -1));
}

static void
	set_group(
		t_s_ucs *stf)
{
	stf->group.first = stf->syls;
	stf->group.sz = U_SYLS;
	if (apstr_purge_ornot(stf->chk, stf->syls, U_SYLS))
		noapstr_grp_props(&stf->group);
	else
		apstr_grp_props_offset(AF_DG, AF_DS, &stf->group);
}

void
	convert_u(
		t_s_pct *chk)
{
	int			pad_indexes[e_pp_sz] = {0};
	t_s_ucs		stf;
	int			r;
	
	stf.chk = chk;
	init_syls(e_sot_c, U_SYLS, stf.syls);
	r = set_uinteger(&stf);
	r |= set_precision(&stf);
	if (r)
	{
		call_tstuffers(g_fstr, &stf, pad_indexes);
		set_group(&stf);
		set_pad_syl(chk, pad_indexes, &stf.group, 1);
		out_syl_groups(&stf.group, 1);
	}
}
