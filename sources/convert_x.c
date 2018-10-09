/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_x.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmauvari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 18:19:32 by nmauvari          #+#    #+#             */
/*   Updated: 2018/10/09 18:22:30 by nmauvari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inner.h"

static t_stuffer	g_fstr[X_SYLS + 1] =
{
	dummy_stuffer,
	cx_hashfix,
	dummy_stuffer,
	cx_prefix,
	cx_digits,
	dummy_stuffer,
	0
};

static int							set_integer(
	t_s_xcs *stf)
{
	t_s_pct		* const chk = stf->chk;
	t_s_arg		* const arg = chk->vaarg;
	size_t		const dsz = g_et_sz[arg->type];
	char const	*syms;
	uintmax_t	d;

	d = 0;
	ft_memcpy(&d, arg->p_val, dsz);
	syms = VTB_HEX_SYMS;
	if (chk->flags & BIGCS_FLAG)
		syms = VTB_BHEX_SYMS;
	stf->p_b = vtb_uv_tscc(d, syms, &stf->b);
	return (d ? 1 : 0);
}


static int							set_precision(
	t_s_pct *chk,
	t_s_xcs *stf)
{
	if (chk->precision && **chk->precision >= 0)
		stf->pre = **chk->precision;
	else
		stf->pre = 1;
	return (stf->pre);
}

static void
	set_group(
		t_s_xcs *stf)
{
	stf->group.first = stf->syls;
	stf->group.sz = X_SYLS;
	if (apstr_purge_ornot(stf->chk, stf->syls, X_SYLS))
		noapstr_grp_props(&stf->group);
	else
		apstr_grp_props_offset(AF_2G, AF_BS, &stf->group);
}

void								convert_x(t_s_pct *chk)
{
	int			pad_indexes[e_pp_sz] = {0};
	t_s_xcs		stf;
	int			r;
	
	stf.chk = chk;
	init_syls(e_sot_c, X_SYLS, stf.syls);
	r = set_integer(&stf);
	r |= set_precision(chk, &stf);
	if (r)
	{
		call_tstuffers(g_fstr, &stf, pad_indexes);
		set_group(&stf);
		set_pad_syl(chk, pad_indexes, &stf.group, 1);
		out_syl_groups(&stf.group, 1);
	}
}
void		convert_big_x(t_s_pct *chk)
{
	chk->flags |= BIGCS_FLAG;
	convert_x(chk);
}
