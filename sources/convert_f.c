/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_f.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmauvari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 16:52:19 by nmauvari          #+#    #+#             */
/*   Updated: 2018/10/25 00:49:02 by nmauvari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inner.h"

#define HIGH_DIG 3
static t_stuffer			g_fstr[F_SYLLABLES + 1] =
{
	dummy_stuffer,
	cf_sign,
	dummy_stuffer,
	cf_highdigits,
	cf_powerzero,
	cf_separator,
	cf_zeros,
	cf_lowdigits,
	dummy_stuffer,
	0
};

#define HIGH_GRP 1
static void							set_syl_grps(
	t_s_fcs *stf)
{
	t_s_so	* const	syls = stf->syls;
	t_s_sgd	ar[F_SYLGRPS] = {
		{&syls[0], 2, 0, 0, 0},
		{&syls[2], 3, 3, -1, '\''},
		{&syls[5], 4, 3, 0, '\''}};
	int		i;

	i = apstr_offset(syls[HIGH_DIG].len, ar[HIGH_GRP].apstr_grp);
	ar[HIGH_GRP].apstr_pos = i;
	ft_memcpy(stf->syl_grps, ar, sizeof(ar));
}

static void							set_precision(
	t_s_pct *chk,
	t_s_fcs *stf)
{
	if (chk->precision && **chk->precision >= 0)
		stf->pre = **chk->precision;
	else
		stf->pre = 6;
}

static int							set_number(
	t_s_fcs *stf)
{
	t_s_fpndfp	num;
	int			roundat;

	get_fpndfp(stf->chk->vaarg, &num);
	if (output_nan_inf(&num.dec, stf->chk))
		return (0);
	stf->number = near_low_pot(&num);
	roundat = -(stf->number.pow10 + stf->pre);
	round_ldouble(&stf->number.times, roundat);
	if (stf->number.times > 10)
	{
		stf->number.times /= 10.0;
		stf->number.pow10++;
	}
	return (1);
}

void								convert_f(
	t_s_pct *chk)
{
	int		* const pads = (int[e_pp_sz]){0};
	t_s_fcs	stf;

	stf.chk = chk;
	set_precision(chk, &stf);
	if (!set_number(&stf))
		return ;
	call_tstuffers(g_fstr, &stf, pads);
	set_syl_grps(&stf);
	set_pad_syl(chk, pads, stf.syl_grps, F_SYLGRPS);
	out_syl_groups(stf.syl_grps, F_SYLGRPS);
}

void								convert_big_f(
	t_s_pct *p_chk)
{
	p_chk->flags |= BIGCS_FLAG;
	convert_f(p_chk);
}
