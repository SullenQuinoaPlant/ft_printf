/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_big_k.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmauvari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 23:22:33 by nmauvari          #+#    #+#             */
/*   Updated: 2018/10/02 00:16:10 by nmauvari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inner.h"

static t_stuffer				g_fstr[BK_SYLS + 1] =
{
	dummy_stuffer,
	dummy_stuffer,
	cbk_dayofweek,
	cbk_dm_sep,
	cbk_month,
	cbk_md_sep,
	cbk_dayofmonth,
	cbk_day_suffix,
	cbk_dy_sep,
	cbk_year,
	dummy_stuffer,
	0
};

void							set_group(
	t_s_bkcs *stf)
{
	stf->group.first = stf->syls;
	stf->group.sz = BK_SYLS;
	noapstr_grp_props(&stf->group);
}

void							init_stuff(
	t_s_pct *chk,
	t_s_bkcs *stf)
{
	stf->chk = chk;
	stf->tm = *(struct tm**)chk->vaarg->p_val;
}

void							convert_big_k(
	t_s_pct *chk)
{
	t_s_bkcs		stf;
	int				pad_indexes[e_pp_sz];

	init_stuff(chk, &stf);
	init_syls(e_sot_cc, BK_SYLS, stf.syls);
	call_tstuffers(g_fstr, &stf, pad_indexes);
	set_group(&stf);
	set_pad_syl(chk, pad_indexes, &stf.group, 
}
