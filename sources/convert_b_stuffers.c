/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_b_stuffers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmauvari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 02:50:33 by nmauvari          #+#    #+#             */
/*   Updated: 2018/10/06 03:05:40 by nmauvari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inner.h"

void								cb_addrprefix(
	int pos,
	void *p)
{
	t_s_bcs *const	stf = (t_s_bcs*)p;
	t_s_so *const	syl = stf->syls + pos;

	syl->type = e_sot_c;
	syl->len = 0;
	if (!(stf->chk->flags & HASH_FLAG))
		return;
	syl->len = 1;
	syl->c = '@';
}


void								cb_addr(
	int pos,
	void *p)
{
	t_s_bcs *const	stf = (t_s_bcs*)p;
	t_s_so *const	syl = stf->syls + pos;
	size_t const	addr_char_sz = sizeof(void*) * CHAR_BIT / 4;
	size_t			addr;
	char const		*base; 

	syl->type = e_sot_cc;
	if (!(syl->len = (stf->chk->flags & HASH_FLAG) ? addr_char_sz : 0))
		return ;
	base = VTB_HEX_SYMS;
	if (stf->chk->flags & PLUS_FLAG)
		base = VTB_BHEX_SYMS;
	ft_memset(stf->addr, '0', VTB_BIGGEST_SIGNED_STRING);
	addr = (uintptr_t)stf->p_mem;
	syl_uv_tob(addr, base, &stf->addr);
	syl->cc = stf->addr + VTB_MIB_OFFSET - addr_char_sz + 1;
	if (stf->chk->flags & APSTR_FLAG)
		syl->type = e_sot_apstr_cc;
}

void						cb_addrpostfix(
	int pos,
	void *p)
{
	t_s_bcs *const	stf = (t_s_bcs*)p;
	t_s_so *const	syl = stf->syls + pos;
	
	syl->type = e_sot_c;
	syl->len = 0;
	if (!(stf->chk->flags & HASH_FLAG))
		return;
	syl->len = 3;
	syl->c = ' ';
}

void						cb_mem(
	int pos,
	void *p)
{
	t_s_bcs *const	stf = (t_s_bcs*)p;
	t_s_so *const	syl = stf->syls + pos;

	syl->len = stf->chk_count * stf->mem_chk_len;
	if (stf->chk->flags & APSTR_FLAG)
		syl->type = e_sot_apstr_f;
	else
		syl->type = e_sot_f;
	syl->arg = p;
	syl->f = tsof_bmem;
	stf->val_p = (t_s_vtb_cc){0, 0};
}
