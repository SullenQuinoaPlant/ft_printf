/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmauvari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 19:35:03 by nmauvari          #+#    #+#             */
/*   Updated: 2018/10/06 03:46:52 by nmauvari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inner.h"

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
	char *const		str = *(char**)stf->chk->vaarg->p_val;

	if (!(stf->chk->flags & HASH_FLAG))
	{
		syl->type = e_sot_cc;
		syl->cc = str;
	}
	else
	{
		syl->type = e_sot_f;
		syl->f = tsof_hash_charstr;
		syl->arg = str;
	}
	if (stf->pre == NULL_TERMED)
		syl->len = ft_strlen(str);
	else
		syl->len = stf->pre;
}

static void							set_wcharstr(
	t_s_scs *stf)
{
	t_s_so *const	syl = stf->syls + CHAR_SYL;
	size_t			len[2];
	size_t			count;
	wchar_t			*str;
	char			ar[UTF8_MAX_CHARS];

	syl->type = e_sot_f;
	syl->f = stf->chk->flags & HASH_FLAG ? tsof_hash_wcharstr : tsof_wcharstr;
	str = *(wchar_t**)stf->chk->vaarg->p_val;
	syl->arg = str;
	len[0] = stf->pre;
	count = 0;
	while (*str && (len[1] = utf8_trueseq(*str++, ar)) <= len[0])
	{
		len[0] -= len[1];
		count++;
	}
	syl->len = stf->pre - len[0];
	if (stf->chk->width && count < (size_t)**stf->chk->width)
		**stf->chk->width += syl->len - count;
}

void								convert_s(
	t_s_pct *chk)
{
	t_s_scs	stf;

	stf.chk = chk;
	if (!*(void**)chk->vaarg->p_val)
	{
		output_null(chk);
		return ;
	}
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
