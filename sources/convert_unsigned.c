#include "ft_printf_inner.h"

static t_stuffer
	g_fstr[D_SYLS] = {
		dummy_stuffer,
		dummy_stuffer,
		cunsigned_prefix,
		cunsigned_hashfix,
		cunsigned_digits,
		dummy_stuffer};

static int
	set_uinteger(
		t_s_unsignedcs *stf, char const * syms)
{
	t_s_pct		* const chk = stf->chk;
	t_s_arg		* const arg = chk->vaarg;
	uintmax_t	d;

	d = 0;
	ft_memcpy(&d, arg->p_val, g_et_sz[arg->type]);
	stf->p_b = my_uv_tob(d, syms, &stf->b);
	return (d ? 1 : 0);
}

static int
	set_precision(
		t_s_unsignedcs *stf)
{
	t_s_pct		* const chk = stf->chk;

	return ((stf->pre = chk->precision ? **chk->precision : -1));
}

static void
	set_group(
		t_s_unsignedcs *stf)
{
	stf->group.first = stf->syls;
	stf->group.sz = O_SYLS;
	if (apstr_purge_ornot(stf->chk, stf->syls, O_SYLS))
		noapstr_grp_props(&stf->group);
	else
		apstr_grp_props_offset(AF_DG, AF_DS, &stf->group);
}

void
	convert_unsigned(
		t_s_pct *chk, char const * base)
{
	int					pad_indexes[e_pp_sz] = {0};
	t_s_unsignedcs		stf;
	int			r;
	
	stf.chk = chk;
	init_syls(e_sot_c, O_SYLS, stf.syls);
	r = set_uinteger(&stf, base);
	r |= set_precision(&stf);
	if (r)
	{
		call_tstuffers(g_fstr, &stf, pad_indexes);
		set_group(&stf);
		set_pad_syl(chk, pad_indexes, &stf.group, 1);
		out_syl_groups(&stf.group, 1);
	}
}
