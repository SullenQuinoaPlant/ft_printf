/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmauvari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 23:08:25 by nmauvari          #+#    #+#             */
/*   Updated: 2018/10/10 18:59:11 by nmauvari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmyfloatingpoint.h"
#include "inner.h"

static t_stuffer			g_fstr[A_SYLLABLES + 1] =
{
	dummy_stuffer,
	ca_prefix,
	dummy_stuffer,
	ca_power0,
	ca_separator,
	ca_mantissa,
	ca_excess_precision,
	ca_to_the_power,
	ca_exponent,
	dummy_stuffer,
	0
};

static void							set_syl_grps(
	t_s_acs *stf)
{
	t_s_so *const	syls = stf->syllables;
	t_s_sgd			ar[A_SYLGRPS] = {
			{&syls[0], 2, 0, 0, 0},
			{&syls[2], 2, 4, 3, '_'},
			{&syls[4], 1, 0, 0, 0},
			{&syls[5], 2, 4, 0, '_'},
			{&syls[7], 1, 0, 0, 0},
			{&syls[8], 1, 3, 0, '\''},
			{&syls[9], 1, 0, 0, 0}};

	ft_memcpy(stf->syl_groups, ar, sizeof(ar));
}

static void							set_float_stuff(
	t_s_pct *chk,
	t_s_acs *stf)
{
	int		shift;

	set_dfp(chk->vaarg, &stf->fpd);
	shift = 0;
	if (chk->vaarg->type == e_double)
		shift = 64 - DB_MANT_PRECISION;
	else if (chk->vaarg->type == e_longdouble)
		shift = 64 - LDB_MANT_PRECISION;
	stf->aligned_mant = stf->fpd.mant << shift;
}

static void							set_precision(
	t_s_pct *chk)
{
	if (chk->precision && **chk->precision < 0)
	{
		**chk->precision = 0;
	}
}

void						convert_a(
	t_s_pct *chk)
{
	int *const	pads = (int[e_pp_sz]){0};
	t_s_acs		stf;

	stf.chk = chk;
	set_precision(chk);
	set_float_stuff(chk, &stf);
	if (output_nan_inf(&stf.fpd, chk))
		return;
	call_tstuffers(g_fstr, &stf, pads);
	set_syl_grps(&stf);
	set_pad_syl(chk, pads, stf.syl_groups, A_SYLGRPS);
	out_syl_groups(stf.syl_groups, A_SYLGRPS);
}

void						convert_big_a(
	t_s_pct *p_chk)
{
	p_chk->flags |= BIGCS_FLAG;
	convert_a(p_chk);
}
