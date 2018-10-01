/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmauvari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 21:46:03 by nmauvari          #+#    #+#             */
/*   Updated: 2018/10/01 21:46:56 by nmauvari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inner.h"

static void						filter_flags(t_s_pct *chk)
{
	chk->flags &= MINUS_FLAG;
}

void							convert_c(
	t_s_pct *chk)
{
	wint_t	c;
	size_t	lens[e_oi_sz];
	char	ar[UTF8_MAX_CHARS];

	filter_flags(chk);
	lens[e_prefix] = 0;
	if (chk->vaarg->type == e_wint_t)
	{
		if ((c = *(wint_t*)chk->vaarg->p_val) == WEOF)
			lens[e_root] = 0;
		else
			lens[e_root] = utf8_trueseq(c, ar);
	}
	else
	{
		*ar = *(unsigned char*)chk->vaarg->p_val;
		lens[e_root] = 1;
	}
	output_padnbuffer(ar, lens, chk);
}

void							convert_big_c(
	t_s_pct *chk)
{
	convert_c(chk);
}
