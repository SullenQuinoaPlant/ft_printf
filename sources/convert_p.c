#include "ft_printf_inner.h"

static t_stuffer
	g_fstr[P_SYLS + 1] = {
		dummy_stuffer,
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
	syms = g_hex_syms;
	if (chk->flags & BIGCS_FLAG)
		syms = g_bhex_syms;
	stf->p_b = my_uv_tob(d, syms, &stf->b);
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

void		convert_x(t_s_pct *chk)
{
	int			pad_indexes[e_pp_sz] = {0};
	t_s_pcs		stf;
	int			r;
	
	stf.chk = chk;
	init_syls(e_sot_c, P_SYLS, stf.syls);
	r = set_address(&stf);
	set_precision(&stf);
	if (r)
	{
		call_tstuffers(g_fstr, &stf, pad_indexes);
		set_group(&stf);
		set_pad_syl(chk, pad_indexes, &stf.group, 1);
		out_syl_groups(&stf.group, 1);
	}
	else
		output_padnbuffer("", (size_t[2]){0, 1}, chk);
}
void		convert_x_big(t_s_pct *chk)
{
	chk->flags |= BIGCS_FLAG;
	convert_x(chk);
}
