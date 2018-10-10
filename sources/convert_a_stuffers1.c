/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_a_stuffers1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmauvari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 23:22:12 by nmauvari          #+#    #+#             */
/*   Updated: 2018/10/10 19:00:13 by nmauvari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inner.h"

void						ca_prefix(
	int syl,
	void *p)
{
	t_s_acs	* const stf = (t_s_acs*)p;
	t_s_pct * const chk = stf->chk;
	int		offset;
	t_s_so	set;

	offset = 0;
	if (stf->fpd.flags & SIGN_F)
		stf->prefix[0] = '-';
	else if (chk->flags & SPACE_FLAG)
		stf->prefix[0] = ' ';
	else if (chk->flags & PLUS_FLAG)
		stf->prefix[0] = '+';
	else
		offset = 1;
	stf->prefix[1] = '0';
	stf->prefix[2] = chk->flags & BIGCS_FLAG ? 'X' : 'x';
	set.len = sizeof(stf->prefix) - offset;
	set.type = e_sot_cc;
	set.cc = stf->prefix + offset;
	stf->syllables[syl] = set;
}

void						ca_power0(
	int syl,
	void *p)
{
	t_s_acs *const	stf = (t_s_acs*)p;
	t_s_so			set;

	set.type = e_sot_cc;
	set.len = 1;
	if (stf->chk->flags & APSTR_FLAG)
		set.type = e_sot_apstr_cc;
	set.cc = &stf->zero;
	stf->zero = stf->fpd.flags & DNORM_F ? '0' : '1';
	stf->syllables[syl] = set;
}

void						ca_separator(
	int syl,
	void *p)
{
	t_s_acs *const	stf = (t_s_acs*)p;
	t_s_so			set;
	int **const		prec = stf->chk->precision;

	set.c = '.';
	set.type = e_sot_c;
	set.len = 0;
	if (stf->chk->flags & HASH_FLAG ||
		(prec && **prec) ||
		(!prec && stf->aligned_mant))
		set.len = 1;
	stf->syllables[syl] = set;
}

/*
**The MAC version of the function does not provide an overflow
**	address in the call to round_ccsyl.
*/
#ifdef PRTF_BEHAVIOR_MAC
void						ca_mantissa(
	int syl,
	void *p)
{
	t_s_acs *const	stf = (t_s_acs*)p;
	char const		*base;
	uint64_t		v;
	t_s_so			set;
	int				pr;

	base = stf->chk->flags & BIGCS_FLAG ? VTB_BHEX_SYMS : VTB_HEX_SYMS;
	v = stf->aligned_mant;
	set = syl_lowv_tob(v, sizeof(v), base, &stf->m);
	set.len = v ? set.len : 0;
	stf->excess = 0;
	if (stf->chk->precision)
	{
		pr = (size_t)**stf->chk->precision;
		if (!round_ccsyl(pr, &set, base, &stf->zero))
			stf->excess = pr - set.len;
	}
	if (stf->chk->flags & APSTR_FLAG)
		set.type = e_sot_apstr_cc;
	stf->syllables[syl] = set;
}
#else
void						ca_mantissa(
	int syl,
	void *p)
{
	t_s_acs *const	stf = (t_s_acs*)p;
	char const		*base;
	uint64_t		v;
	t_s_so			set;
	int				pr;

	base = stf->chk->flags & BIGCS_FLAG ? VTB_BHEX_SYMS : VTB_HEX_SYMS;
	v = stf->aligned_mant;
	set = syl_lowv_tob(v, sizeof(v), base, &stf->m);
	set.len = v ? set.len : 0;
	stf->excess = 0;
	if (stf->chk->precision &&
		**stf->chk->precision >= 0)
	{
		pr = (size_t)**stf->chk->precision;
		if (!round_ccsyl(pr, &set, base, &stf->zero))
			stf->excess = pr - set.len;
	}
	if (stf->chk->flags & APSTR_FLAG)
		set.type = e_sot_apstr_cc;
	stf->syllables[syl] = set;
}
#endif

void	ca_excess_precision(int syl, void *p)
{
	t_s_acs	* stf = (t_s_acs*) p;
	t_s_so	set;

	if (stf->chk->flags & APSTR_FLAG)
		set.type = e_sot_apstr_c;
	else
		set.type = e_sot_c;
	set.c = '0';
	if (stf->excess > 0)
		set.len = stf->excess;
	else
		set.len = 0;
	stf->syllables[syl] = set;
}
