#include "inner.h"

static t_stuffer
	g_fstr[P_SYLS + 1] = {
		dummy_stuffer,
		cp_sign,
		cp_hashfix,
		dummy_stuffer,
		cp_prefix,
		cp_digits,
		dummy_stuffer,
		0};

static int
	set_address(
		t_s_pcs *stf)
{
	t_s_pct		* const chk = stf->chk;
	t_s_arg		* const arg = chk->vaarg;
	size_t		const dsz = g_et_sz[arg->type];
	char const	*syms;
	uintmax_t	d;

	d = 0;
	ft_memcpy(&d, arg->p_val, dsz);
	syms = VTB_HEX_SYMS;
	if (chk->flags & BIGCS_FLAG)
		syms = VTB_BHEX_SYMS;
	stf->p_b = vtb_uv_tscc(d, syms, &stf->b);
	return (d ? 1 : 0);
}

static int
	set_precision(
		t_s_pcs *stf)
{
	t_s_pct		* const chk = stf->chk;

	return ((stf->pre = chk->precision ? **chk->precision : -1));
}

static void
	set_group(
		t_s_pcs *stf)
{
	stf->group.first = stf->syls;
	stf->group.sz = P_SYLS;
	if (apstr_purge_ornot(stf->chk, stf->syls, P_SYLS))
		noapstr_grp_props(&stf->group);
	else
		apstr_grp_props_offset(AF_2G, AF_BS, &stf->group);
}

void
	convert_p(
		t_s_pct *chk)
{
	int			pad_indexes[e_pp_sz] = {0};
	t_s_pcs		stf;
	char		* const nil = "(nil)";
	
	stf.chk = chk;
	init_syls(e_sot_c, P_SYLS, stf.syls);
	set_precision(&stf);
	if (set_address(&stf))
	{
		call_tstuffers(g_fstr, &stf, pad_indexes);
		set_group(&stf);
		set_pad_syl(chk, pad_indexes, &stf.group, 1);
		out_syl_groups(&stf.group, 1);
	}
	else
	{
		chk->flags &= ~ZERO_FLAG;
		output_padnbuffer(nil, (size_t[2]){0, ft_strlen(nil)}, chk);
	}
}

void
	convert_big_p(
		t_s_pct *chk)
{
	chk->flags |= BIGCS_FLAG;
	convert_x(chk);
}
