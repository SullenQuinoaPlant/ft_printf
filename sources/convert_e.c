#include "inner.h"

static t_stuffer
	g_fstr[E_SYLLABLES + 1] = {
		ce_sign,
		ce_zero,
		ce_separator,
		ce_lowdigits,
		ce_to_the_power,
		ce_exponent_sign,
		ce_exponent_pad,
		ce_exponent,
		0
};

static t_oa
	g_outputters = {
		&ce_prefix,
		&ce_body
};

static void
	set_precision(
		t_s_pct *chk, t_s_ecs *stf)
{
	if (chk->precision)
		stf->pre = **chk->precision;
	else
		stf->pre = 6;
}

static void
	set_number(
		t_s_fpndfp *num, t_s_ecs *stf)
{
	stf->number = near_low_pot(num);
	round_ldouble(&stf->number.times, -stf->pre);
}

static void
	set_exponent(
		int	pow10, t_s_cc *p, t_mib *here)
{
	*p = my_v_tob(pow10, g_dec_syms, here, e_all);
}
		
#define EXP_DIG 7
#define EXP_GRP 3
static void
	set_syl_grps(t_s_ecs *stf)
{
	t_s_so	* const syls = stf->syls;
	t_s_sgd	ar[E_SYLGRPS] = {
			{&syls[0], 1, 3, 2, '\''},
			{&syls[1], 2, 3, 2, '@'},
			{&syls[3], 1, 3, 0, '\''},
			{&syls[4], 4, 3, -1, '\''}};
	int		i;

	i = apstr_offset(syls[EXP_DIG].len, ar[EXP_GRP].apstr_grp);
	ar[EXP_GRP].apstr_pos = i;
	ft_memcpy(stf->syl_grps, ar, sizeof(ar));
}

void		convert_e(t_s_pct *chk)
{
	t_s_ecs		stf;
	size_t		out_len;
	t_s_fpndfp	num;

	get_fpndfp(chk->vaarg, &num);
	if (output_nan_inf(&num.dec, chk))
		return;
	stf.chk = chk;
	set_precision(chk, &stf);
	set_number(&num, &stf);
	set_exponent(stf.number.pow10, &stf.p_exp, &stf.exp);
	init_syls(e_sot_c, E_SYLLABLES, stf.syls);
	call_tstuffers(g_fstr, &stf, 0);
	apstr_purge_ornot(chk, stf.syls, E_SYLLABLES);
	set_syl_grps(&stf);
	out_len = sylgrps_outlen(stf.syl_grps, E_SYLGRPS);
	output_padnstuff(out_len, chk, g_outputters, &stf);
}

void		convert_e_big(t_s_pct *p_chk)
{
	p_chk->flags |= BIGCS_FLAG;
	convert_e(p_chk);
}
