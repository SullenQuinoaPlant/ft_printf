/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_g.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmauvari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 12:45:10 by nmauvari          #+#    #+#             */
/*   Updated: 2018/10/09 18:05:01 by nmauvari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inner.h"

#define GRP_SETTER 1
static t_stuffer		g_estyle[G_ESYLS + GRP_SETTER + 1] =
{
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

static t_stuffer		g_fstyle[G_FSYLS + GRP_SETTER + 1] =
{
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

static void						set_precision(
	t_s_pct *chk,
	t_s_gcs *stf)
{
	if (chk->precision)
	{
		if (**chk->precision < 0)
			stf->pre = (chk->len_mod == e_bigl) ? 17 : 20;
		else if (!(stf->pre = **chk->precision))
			stf->pre = 1;
	}
	else
		stf->pre = 6;
}

static int						set_number(
	t_s_gcs *stf)
{
	t_s_fpndfp	num;

	get_fpndfp(stf->chk->vaarg, &num);
	if (output_nan_inf(&num.dec, stf->chk))
		return (0);
	stf->number = near_low_pot(&num);
#ifndef MINE
	if (!stf->number.pow10)
		round_ldouble_weird(&stf->number.times, -stf->pre + 1);
	else
		round_ldouble(&stf->number.times, -stf->pre + 1);
#else
	round_ldouble(&stf->number.times, -stf->pre + 1);
#endif
	if (stf->number.times >= 10)
	{
		stf->number.times /= 10.0;
		stf->number.pow10 += 1;
	}
	return (1);
}

static t_stuffer				*choose_pattern(
	t_s_gcs *stf)
{
	int		const pow10 = stf->number.pow10;
	
	if (pow10 < -4 || pow10 >= stf->pre)
		return (g_estyle);
	else
		return (g_fstyle);
}

void							convert_g(t_s_pct *chk)
{
	int *const	pads = (int[e_pp_sz]){0};
	t_s_gcs		stf;

	stf.chk = chk;
	set_precision(chk, &stf);
	if (!set_number(&stf))
		return;
	init_syls(e_sot_c, G_SYLLABLES, stf.syls);
	call_tstuffers(choose_pattern(&stf), &stf, pads);
	apstr_purge_ornot(stf.chk, stf.syls, G_SYLLABLES);
	set_pad_syl(chk, pads, stf.syl_grps, G_SYLGRPS);
	out_syl_groups(stf.syl_grps, G_SYLGRPS);
}

void							convert_big_g(t_s_pct *p_chk)
{
	p_chk->flags |= BIGCS_FLAG;
	convert_g(p_chk);
}
