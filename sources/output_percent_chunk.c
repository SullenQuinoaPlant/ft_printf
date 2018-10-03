/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_percent_chunk.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmauvari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 22:42:49 by nmauvari          #+#    #+#             */
/*   Updated: 2018/09/21 23:21:01 by nmauvari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inner.h"

static void							(*const f_ar[e_cs_sz])(t_s_pct *) =
{
	convert_nospec,
	convert_a,
	convert_big_a,
	convert_b,
	convert_big_b,
	convert_c,
	convert_big_c,
	convert_d,
	convert_big_d,
	convert_e,
	convert_big_e,
	convert_f,
	convert_big_f,
	convert_g,
	convert_big_g,
	convert_i,
	convert_k,
	convert_big_k,
	convert_n,
	convert_big_n,
	convert_o,
	convert_big_o,
	convert_p,
	convert_big_p,
	convert_r,
	convert_big_r,
	convert_s,
	convert_big_s,
	convert_u,
	convert_big_u,
	convert_x,
	convert_big_x
};

static void							filter_flags(
	t_s_pct *p_chk)
{
	char	f_cpy;
	t_e_cs	spe;

	f_cpy = p_chk->flags;
	if (f_cpy & MINUS_FLAG ||
		(p_chk->precision && ((spe = p_chk->specifier) == e_d ||
		spe == e_bigd || spe == e_i || spe == e_o || spe == e_bigo ||
		spe == e_u || spe == e_bigu || spe == e_x || spe == e_big)))
		f_cpy &= ~(ZERO_FLAG);
	if (f_cpy & PLUS_FLAG)
		f_cpy &= ~(SPACE_FLAG);
	p_chk->flags = f_cpy;
}

static void							filter_width(
	t_s_pct *p_chk)
{
	int		wd;

	if (!p_chk->width)
		return;
	wd = **p_chk->width;
	if (wd < 0)
	{
		p_chk->flags |= MINUS_FLAG;
		wd = wd == INT_MIN ? -(1 + wd) : -wd;
		**p_chk->width = wd;
	}
}

static void							filter_precision(
	t_s_pct *chk)
{
	if (chk->precision &&
		**chk->precision < 0 &&
		!(chk->specifier == e_b || chk->specifier == e_B))
		**chk->precision = 0;
}

void								output_pct_chk(
	t_s_pct *p_chk)
{
	filter_width(p_chk);
	filter_flags(p_chk);
	filter_precision(p_chk);
	f_ar[p_chk->specifier](p_chk);
}
