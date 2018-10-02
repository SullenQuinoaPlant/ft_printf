/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_o.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmauvari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 22:28:19 by nmauvari          #+#    #+#             */
/*   Updated: 2018/09/21 22:35:35 by nmauvari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inner.h"

static t_stuffer					g_fstr[O_SYLS + 1] =
{
	dummy_stuffer,
	dummy_stuffer,
	co_prefix,
	co_hashfix,
	co_digits,
	dummy_stuffer,
	0
};

static int							set_integer(
	t_s_ocs *stf)
{
	t_s_pct *const	chk = stf->chk;
	t_s_arg *const	arg = chk->vaarg;
	size_t const	dsz = g_et_sz[arg->type];
	uintmax_t		d;

	d = 0;
	ft_memcpy(&d, arg->p_val, dsz);
	stf->p_b = vtb_uv_tscc(d, VTB_OCT_SYMS, &stf->b);
	return (d ? 1 : 0);
}

static int							set_precision(
	t_s_ocs *stf)
{
	t_s_pct *const	chk = stf->chk;

	return ((stf->pre = chk->precision ? **chk->precision : -1));
}

static void							set_group(
	t_s_ocs *stf)
{
	stf->group.first = stf->syls;
	stf->group.sz = O_SYLS;
	if (apstr_purge_ornot(stf->chk, stf->syls, O_SYLS))
		noapstr_grp_props(&stf->group);
	else
		apstr_grp_props_offset(AF_4G, AF_BS, &stf->group);
}

void								convert_o(
	t_s_pct *chk)
{
	int			pad_indexes[e_pp_sz];
	t_s_ocs		stf;
	int			r;

	stf.chk = chk;
	init_syls(e_sot_c, O_SYLS, stf.syls);
	r = set_integer(&stf);
	r |= set_precision(&stf);
	if (r)
	{
		call_tstuffers(g_fstr, &stf, pad_indexes);
		set_group(&stf);
		set_pad_syl(chk, pad_indexes, &stf.group, 1);
		out_syl_groups(&stf.group, 1);
	}
}

void								convert_big_o(
	t_s_pct *chk)
{
	convert_o(chk);
}
