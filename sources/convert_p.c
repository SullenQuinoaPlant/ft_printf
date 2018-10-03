/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmauvari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 22:57:11 by nmauvari          #+#    #+#             */
/*   Updated: 2018/09/21 23:14:28 by nmauvari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inner.h"

static t_stuffer					g_fstr[P_SYLS + 1] =
{
	dummy_stuffer,
	cp_signfix,
	cp_hashfix,
	dummy_stuffer,
	cp_prefix,
	cp_digits,
	dummy_stuffer,
	0
};

static int							set_address(
	t_s_pcs *stf)
{
	t_s_pct *const	chk = stf->chk;
	t_s_arg *const	arg = chk->vaarg;
	size_t const	dsz = g_et_sz[arg->type];
	char const		*syms;
	uintmax_t		d;

	d = 0;
	ft_memcpy(&d, arg->p_val, dsz);
	syms = VTB_HEX_SYMS;
	if (chk->flags & BIGCS_FLAG)
		syms = VTB_BHEX_SYMS;
	stf->p_b = vtb_uv_tscc(d, syms, &stf->b);
	return (d ? 1 : 0);
}

static int							set_precision(
	t_s_pcs *stf)
{
	t_s_pct *const	chk = stf->chk;

	return ((stf->pre = chk->precision ? **chk->precision : -1));
}

static void							set_group(
	t_s_pcs *stf)
{
	stf->group.first = stf->syls;
	stf->group.sz = P_SYLS;
	if (apstr_purge_ornot(stf->chk, stf->syls, P_SYLS))
		noapstr_grp_props(&stf->group);
	else
		apstr_grp_props_offset(AF_2G, AF_BS, &stf->group);
}

void								convert_p(
	t_s_pct *chk)
{
	int			pad_indexes[e_pp_sz] = {0};
	t_s_pcs		stf;

	stf.chk = chk;
	if (!*(void**)chk->vaarg->p_val)
	{
		output_nil(chk);
		return ;
	}
	init_syls(e_sot_c, P_SYLS, stf.syls);
	set_precision(&stf);
	set_address(&stf);
	call_tstuffers(g_fstr, &stf, pad_indexes);
	set_group(&stf);
	set_pad_syl(chk, pad_indexes, &stf.group, 1);
	out_syl_groups(&stf.group, 1);
}

void								convert_big_p(
	t_s_pct *chk)
{
	chk->flags |= BIGCS_FLAG;
	convert_p(chk);
}
