/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_g_fstuffers1.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmauvari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 12:50:37 by nmauvari          #+#    #+#             */
/*   Updated: 2018/10/09 12:52:01 by nmauvari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inner.h"

void						cg_fsign(
	int pos,
	void *p)
{
	t_s_gcs	* const stf = (t_s_gcs*)p;
	t_s_so	* const syl = stf->syls + pos;

	syl->len = 1;
	if (stf->number.times < 0)
		syl->c = '-';
	else if (stf->chk->flags & SPACE_FLAG)
		syl->c = ' ';
	else if (stf->chk->flags & PLUS_FLAG)
		syl->c = '+';
	else
		syl->len = 0;
}

void						cg_fhighdigits(
	int pos,
	void *p)
{
	t_s_gcs	* const stf = (t_s_gcs*)p;
	t_s_so	* const syl = stf->syls + pos;
	int		i;

	syl->type = e_sot_apstr_f;
	syl->f = tsof_out_eat_tspot;
	syl->arg = &stf->number;
	if ((i = stf->number.pow10 + 1) <= 0)
		syl->len = 0;
	else
	{
		syl->len = i;
		stf->pre -= i;
	}
}

void						cg_fpowerzero(
	int pos,
	void *p)
{
	t_s_gcs	* const stf = (t_s_gcs*)p;
	t_s_so	* const syl = stf->syls + pos;

	syl->type = e_sot_apstr_c;
	syl->c = '0';
	syl->len = stf->number.pow10 < 0 ? 1 : 0;
}

void						cg_fseparator(
	int pos,
	void *p)
{
	t_s_gcs	* const stf = (t_s_gcs*)p;
	t_s_so	* const syl = stf->syls + pos;

	syl->c = '.';
	if (stf->pre || stf->chk->flags & HASH_FLAG)
		syl->len = 1;
}

void						cg_fzeros(
	int pos,
	void *p)
{
	t_s_gcs	* const stf = (t_s_gcs*)p;
	t_s_so	* const syl = stf->syls + pos;

	syl->type = e_sot_apstr_c;
	syl->c = '0';
	if (stf->number.pow10 < -1 && stf->pre)
		syl->len = -(stf->number.pow10 + 1);
}
