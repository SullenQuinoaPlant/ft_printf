/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_g_estuffers1.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmauvari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 13:46:04 by nmauvari          #+#    #+#             */
/*   Updated: 2018/10/09 13:47:19 by nmauvari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inner.h"


void							cg_esign(
	int pos,
	void *s)
{
	t_s_gcs	* const stf = (t_s_gcs*)s;
	t_s_so	* const syl = stf->syls + pos;

	syl->len = 1;
	if (stf->number.times < 0)
		syl->c = '-';
	else if (stf->chk->flags & PLUS_FLAG)
		syl->c = '+';
	else if (stf->chk->flags & SPACE_FLAG)
		syl->c = ' ';
	else
		syl->len = 0;
}

void							cg_ezero(
	int pos,
	void *s)
{
	t_s_gcs	* const stf = (t_s_gcs*)s;
	t_s_so	* const syl = &stf->syls[pos];

	syl->len = 1;
	syl->type = e_sot_apstr_f;
	syl->f = &tsof_out_eat_tspot;
	syl->arg = &stf->number;
	stf->pre--;
}

void							cg_eseparator(
	int pos,
	void *s)
{
	t_s_gcs	* const stf = (t_s_gcs*)s;

	stf->syls[pos].c = '.';
	stf->syls[pos].len = 1;
	if (!(stf->pre || stf->chk->flags & HASH_FLAG))
		stf->syls[pos].len = 0;
}

#define SEPARATOR_REL_POS 1
void							cg_elowdigits(
	int pos,
	void *s)
{
	t_s_gcs	* const stf = (t_s_gcs*)s;
	t_s_so	* const syl = &stf->syls[pos];

	if (!(stf->chk->flags & HASH_FLAG) &&
		!(stf->pre -= trailing_zeros(stf->number.times, 1, stf->pre)))
		(syl - SEPARATOR_REL_POS)->len = 0;
	syl->len = stf->pre;
	syl->type = e_sot_apstr_f;
	syl->f = &tsof_out_eat_tspot;
	syl->arg = &stf->number;
}

void							cg_eto_the_power(
	int pos,
	void *s)
{
	t_s_gcs	* const stf = (t_s_gcs*)s;
	t_s_so	* const syl = &stf->syls[pos];

	syl->len = 1;
	if (stf->chk->flags & BIGCS_FLAG)
		syl->c = 'E';
	else
		syl->c = 'e';
}
