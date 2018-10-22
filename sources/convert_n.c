/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_n.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmauvari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 21:12:38 by nmauvari          #+#    #+#             */
/*   Updated: 2018/09/21 21:31:13 by nmauvari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inner.h"

static t_e_t
	g_target_et[e_lm_sz] = {
		e_int,
		e_char,
		e_short,
		e_long,
		e_longlong,
		e_int,
		e_intmax_t,
		e_ssize_t,
		e_ptrdiff_t
};

void					convert_n(
	t_s_pct *chk)
{
	void *const	p = *(void**)chk->vaarg->p_val;
	intmax_t	val;
	size_t		sz;

	if (!p)
		return ;
	sz = g_et_sz[g_target_et[chk->len_mod]];
	if (g_os.output_len >= (uintmax_t)1 << (sz * CHAR_BIT - 1))
		val = -1;
	else
		val = g_os.output_len;
	ft_memcpy(p, &val, sz);
}

void					convert_big_n(
	t_s_pct *chk)
{
	size_t *const	p = *(size_t**)chk->vaarg->p_val;

	if (p)
		*p = g_os.output_len;
}
