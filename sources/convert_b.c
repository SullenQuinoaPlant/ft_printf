#include "ft_printf_inner.h"

static t_e_t
	g_target_et[e_lm_sz] = {
		e_int,
		e_char,
		e_short,
		e_long,
		e_longlong,
		e_int,
		e_intmax_t,
		e_size_t,
		e_ptrdiff_t
};

static
void
	set_base(
		t_s_pct *chk)
{
	if (chk->specifier == e_b)
		stf->base = g_bin_syms;
	else if (chk->flags & PLUS_FLAG)
		stf->base = g_bhex_syms;
	else
		stf->base = g_hex_syms;
}

static
void
	set_mem_opts(
		t_s_pct *chk, t_s_bcs *stf)
{
	if (chk->precision)
		stf->chk_count = **chk->precision;
	else
		stf->chk_count = 1;
	stf->mem_chk = g_et_sz[g_target_et[chk->len_mod]];
	p_mem = chk->vaarg->p_val;
}

static
t_stuffer
	g_fstr[B_SYLS + 1] = {
	dummy_stuffer,
	cd_addrprefix,
	cd_addr,
	cd_addrpostfix,
	dummy_stuffer,
	cd_mem,
	dummy_stuffer,
	0
};

static
void
	set_syl_grps(
		t_s_bcs *stf)
{
	t_s_so	* const syls = stf->syls;
	t_s_sgd	ar[B_SYLGRPS] = {
		{&syls[0], 4, 8, 0, '`'},
		{&syls[4], 3, -1, 0, ' '}};
	size_t	grp;

	grp = stf->mem_chk * CHAR_BIT / my_flog2(stf->base);
	ar[MEM_GRP].apstr_grp = grp;
	ft_memcpy(stf->syl_grps, ar, sizeof(ar));
}

void
	convert_b(
		t_s_pct *chk)
{
	t_s_bcs		stf;

	stf.chk = chk;
	set_base(&stf);
	set_mem_options(chk, &stf);
	call_tstuffers(g_fstr, &stf, pads);
	set_syl_grps(&stf);
	set_pad_syl(chk, pads, stf.syl_grps, B_SYLGRPS);
	stf.syls[pads[e_pp_middle]].c = '.';
	out_syl_groups(stf.syl_grps, B_SYLGRPS);
}

void
	convert_bigb(
		t_s_pct *chk)
{
	convert_b_big(chk);
}
