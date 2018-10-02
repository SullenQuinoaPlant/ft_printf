/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmauvari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 19:35:03 by nmauvari          #+#    #+#             */
/*   Updated: 2018/09/21 20:08:59 by nmauvari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inner.h"

static void							filter_flags(
	t_s_pct *chk)
{
	chk->flags &= ~(APSTR_FLAG);
}

#define NULL_TERMED -1
static void							get_precision(
	t_s_pct *chk,
	t_s_scs *stf)
{
	if (chk->precision)
		stf->pre = **chk->precision;
	else
		stf->pre = NULL_TERMED;
}

#define CHAR_SYL 2
static void							set_charstr(
	t_s_scs *stf)
{
	t_s_so *const	syl = stf->syls + CHAR_SYL;

	if (!stf->flags & HASH_FLAG)
	{
		syl->type = e_sot_cc;
		syl->cc = *(char**)stf->chk->vaarg->p_val;
	}
	else
	{
		syl->type = e_sot_f;
		syl->f = tsof_hash_charstr;
	}
	if (stf->pre == NULL_TERMED)
		syl->len = ft_strlen(syl->cc);
	else
		syl->len = stf->pre;
}

static void							set_wcharstr(
	t_s_scs *stf)
{
	t_s_so *const	syl = stf->syls + CHAR_SYL;
	size_t			left;
	size_t			r;
	wchar_t			*str;
	char			ar[UTF8_MAX_CHARS];

	syl->type = e_sot_f;
	syl->f  = tsof_wcharstr;
	if (stf->flags & HASH_FLAG)
		syl->f = tsof_hash_wcharstr;
	str = *(wchar_t**)stf->chk->vaarg->p_val;
	syl->arg = str;
	left = stf->pre;
	while (*str && (r = utf8_trueseq(*str++, ar)) <= left)
		left -= r;
	syl->len = stf->pre - left;
}

void								convert_s(
	t_s_pct *chk)
{
	t_s_scs	stf;

	stf.chk = chk;
	filter_flags(chk);
	get_precision(chk, &stf);
	if (chk->vaarg->type == e_wchar_tptr)
		set_wcharstr(&stf);
	else
		set_charstr(&stf);
	set_pad_syl(chk, (int[3]){0, 1, 3}, &(t_s_sgd){stf.syls, 4, 0, 0, 0}, 1);
	output_syllables(stf.syls, S_SYLLABLES);
}

void								convert_big_s(
	t_s_pct *chk)
{
	convert_s(chk);
}
