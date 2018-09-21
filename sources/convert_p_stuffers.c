/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_p_stuffers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmauvari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 23:04:50 by nmauvari          #+#    #+#             */
/*   Updated: 2018/09/21 23:11:21 by nmauvari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inner.h"

void							cp_hashfix(
	int pos,
	void *p)
{
	t_s_pcs *const	stf = (t_s_pcs*)p;
	t_s_so *const	syl = stf->syls + pos;

	syl->cc = "0x";
	syl->len = ft_strlen(syl->cc);
	syl->type = e_sot_cc;
}

void							cp_prefix(
	int pos,
	void *p)
{
	t_s_pcs *const	stf = (t_s_pcs*)p;
	t_s_so *const	syl = stf->syls + pos;

	syl->type = e_sot_apstr_c;
	syl->c = '0';
	if (stf->pre > 0 && stf->p_b.len < (size_t)stf->pre)
		syl->len = stf->pre - stf->p_b.len;
}

void							cp_digits(
	int pos,
	void *p)
{
	t_s_pcs *const	stf = (t_s_pcs*)p;
	t_s_so *const	syl = stf->syls + pos;

	syl->type = e_sot_apstr_cc;
	syl->cc = stf->p_b.c;
	syl->len = stf->p_b.len;
}
