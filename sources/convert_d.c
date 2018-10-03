/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmauvari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 22:38:24 by nmauvari          #+#    #+#             */
/*   Updated: 2018/09/21 22:40:55 by nmauvari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inner.h"

static t_stuffer					g_fstr[D_SYLS + 1] =
{
		dummy_stuffer,
		cd_sign,
		dummy_stuffer,
		cd_prefix,
		cd_digits,
		dummy_stuffer,
		0
};

static int							set_integer(
	t_s_dcs *stf)
{
	t_s_pct *const	chk = stf->chk;
	t_s_arg *const	arg = chk->vaarg;
	size_t const	dsz = g_et_sz[arg->type];
	intmax_t		d;

	d = 0;
	ft_memcpy(&d, arg->p_val, dsz);
	if (d & (((intmax_t)1) << ((CHAR_BIT * dsz) - 1)))
		d |= ~((((intmax_t)1) << (CHAR_BIT * dsz)) - 1);
	stf->p_b = vtb_sv_tscc(d, VTB_DEC_SYMS, &stf->b, e_vtb_spall);
	return (d ? 1 : 0);
}

static int							set_precision(
	t_s_dcs *stf)
{
	t_s_pct *const	chk = stf->chk;

	return ((stf->pre = chk->precision ? **chk->precision : 1));
}

static void							set_group(
	t_s_dcs *stf)
{
	stf->group.first = stf->syls;
	stf->group.sz = D_SYLS;
	if (apstr_purge_ornot(stf->chk, stf->syls, D_SYLS))
		noapstr_grp_props(&stf->group);
	else
		apstr_grp_props_offset(AF_DG, AF_DS, &stf->group);
}

void								convert_d(
	t_s_pct *chk)
{
	int			pad_indexes[e_pp_sz];
	t_s_dcs		stf;
	int			r;
	
	stf.chk = chk;
	init_syls(e_sot_c, D_SYLS, stf.syls);
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

void								convert_big_d(
	t_s_pct *chk)
{
	chk->len_mod = e_l;
	convert_d(chk);
}
