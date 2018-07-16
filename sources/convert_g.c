#include "ft_printf_inner.h"

#define GRP_SETTER 1
static t_stuffer
		g_estyle[G_FSYLS + GRP_SETTER + 1] = {
	dummy_stuffer,
	cg_esign,
	dummy_stuffer,
	cg_ezero,
	cg_eseparator,
	cg_elowdigits,
	cg_eto_the_power,
	cg_eexponent_sign,
	cg_eexponent_pad,
	cg_eexponent,
	dummy_stuffer,
	cg_esetgroups,
	0
};

static t_stuffer
		g_fstyle[G_FSYLS + GRP_SETTER + 1] = {
	dummy_stuffer,
	cg_fsign,
	dummy_stuffer,
	cg_fhighdigits,
	cg_fpowerzero,
	cg_fseparator,
	cg_fzeros,
	cg_flowdigits,
	dummy_stuffer,
	cg_fsetgroups,
	0
};

static void
	set_precision(
		t_s_gcs *stf)
{
	if (stf->chk->precision)
		stf->pre = **stf->chk->precision;
	else
		stf->pre = 6;
}

static int
	set_number(
		t_s_gcs *stf)
{
	t_s_fpndfp	num;
	int			roundat;

	get_fpndfp(stf->chk->vaarg, &num);
	if (output_nan_inf(&num.dec, stf->chk))
		return (0);
	stf->number = near_low_pot(&num);
	roundat = -(stf->number.pow10 + stf->pre);
	round_ldouble(&stf->number.times, roundat);
	return (1);
}

static void
	choose_pattern(
		t_s_gcs *stf, t_stuffer const **pattern)
{
	int		const pow10 = stf->number.pow10;
	
	if (pow10 < -4 || pow10 >= stf->pre)
		*pattern = g_estyle;
	else
		*pattern = g_fstyle;
}

void		convert_g(t_s_pct *chk)
{
	int			* const pads = (int[e_pp_sz]){0};
	t_s_gcs		stf;
	t_stuffer	const *pattern;

	stf.chk = chk;
	set_precision(&stf);
	if (!set_number(&stf))
		return;
	choose_pattern(&stf, &pattern);
	stuff_stuff(pattern, &stf, pads);
	set_pad_syl(chk, pads, stf.syl_grps, G_SYLGRPS);
	out_syl_groups(stf.syl_grps, G_SYLGRPS);
}

void		convert_g_big(t_s_pct *p_chk)
{
	p_chk->flags |= BIGCS_FLAG;
	convert_g(p_chk);
}
