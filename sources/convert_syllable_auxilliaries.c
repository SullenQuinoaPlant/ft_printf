/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_syllable_auxilliaries.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmauvari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 23:23:02 by nmauvari          #+#    #+#             */
/*   Updated: 2018/10/12 04:49:38 by nmauvari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inner.h"

size_t
	syls_outlen(
		t_s_so *syl, int count, size_t apstr_grp)
{
	t_s_so	* const lim = syl + count;
	size_t	total_len;
	size_t	apstr_len;
	t_e_sot	type;

	total_len = 0;
	apstr_len = 0;
	while (syl < lim)
		if ((type = syl->type) == e_sot_apstr_cc ||
			type == e_sot_apstr_c ||
			type == e_sot_apstr_f)
			apstr_len += (syl++)->len;
		else
			total_len += (syl++)->len;
	total_len += apstr_len_raw(apstr_len, apstr_grp);
	return (total_len);
}

size_t	sylgrps_outlen(t_s_sgd grp[], int count)
{
	t_s_sgd	* const lim = grp + count;
	size_t	total_len;
	t_s_so	* first;
	size_t	grp_sz;
	size_t	grp_by;

	total_len = 0;
	while (grp < lim)
	{
		first = grp->first;
		grp_sz = grp->sz;
		grp_by = grp->apstr_grp;
		total_len += syls_outlen(first, grp_sz, grp_by);
		grp++;
	}
	return (total_len);
}

size_t	tssos_lensum(t_s_so stack[], int len)
{
	t_s_so	* const limit = stack + len;
	size_t	ret;

	ret = 0;
	while (stack++ < limit)
		ret += stack->len;
	return (ret);
}

static int						add_carry(
	char const *base,
	t_s_so *syl,
	size_t at,
	char *overflow)
{
	size_t const	base_len = ft_strlen(base);
	char const		biggest = base[base_len - 1];

	while (at && syl->cc[at - 1] == biggest)
		syl->cc[--at] = *base;
	if (at--)
	{
		while (*base++ != syl->cc[at])
			;
		syl->cc[at] = *base;
	}
	else
	{
		while (*base++ != *overflow && *base != biggest)
			;
		if (*overflow == *base)
			return (-1);
		*overflow = *base;
	}
	return (0);
}

static int						has_tail(
	t_s_so *syl,
	size_t at,
	char const *base)
{
	char const	zero = base[0];
	size_t		i;

	i = syl->len - 1;
	while (i > at)
		if (syl->cc[i--] != zero)
			return (1);
	return (0);
}

static int						less_eq_more_than_mid(
	char c,
	char const *base)
{
	int const	base_len = ft_strlen(base);
	int			pos;
	char		mid;

	pos = -1;
	while (++pos < base_len)
		if (base[pos] == c)
			break;
	if (pos < (mid = base_len / 2))
		return (-1);
	else if (pos == mid)
		return (0);
	else
		return (1);
}

static int						is_even(
	char c,
	char const *base)
{
	int		evenness;

	evenness = 1;
	while (c != *base++)
		evenness = !evenness;
	return (evenness);
}

#if defined PRTF_BEHAVIOR_MINE || PRTF_BEHAVIOR_MAC || PRTF_BEHAVIOR_GNU
int								round_ccsyl(
	size_t at,
	t_s_so *syl,
	char const *base,
	char *overflow)
{
	int		carry;
	char	prv;
	int		rel;

	if (at >= syl->len)
		return (0);
	prv = at ? syl->cc[at - 1] : *overflow;
	carry = 0;
	if ((rel = less_eq_more_than_mid(syl->cc[at], base)) == 1 ||
		(!rel && (0 ||
# ifdef PRTF_ROUNDING_BEHAVIOR_NEAR_EVEN
		!is_even(prv, base) ||
# endif
		has_tail(syl, at, base))))
		carry = 1;
	syl->len = at;
	if (carry && add_carry(base, syl, at, overflow))
		return (-1);
	return (1);
}
#endif

/*
**Couldn't figure it out. Tired.
**I consider the above function's behavior to be sensible enough.
**Left the following for examples as to what I tried.
**But I couldn't reproduce the rounding technique employed, couldn't find an
**	indication on the web as to which rounding method is desired in this case,
**	and looking at the sources would be the same as copy-pasting.
**So things are probably going to stay the way they are.
**#ifdef PRTF_BEHAVIOR_MAC
**int								round_ccsyl(
**	size_t at,
**	t_s_so *syl,
**	char const *base,
**	char *overflow)
**{
**	int			carry;
**	char		prv;
**	int			rel;
**
**	if (at >= syl->len)
**		return (0);
**	prv = at ? syl->cc[at - 1] : *overflow;
**	carry = 0;
**	if ((rel = less_eq_more_than_mid(syl->cc[at], base)) == 1 ||
**		(rel == 0 &&
**		((has_tail(syl, at, base)) || (!is_even(prv, base)))))
**		carry = 1;
**	if (carry && add_carry(base, syl, at, overflow))
**		return (-1);
**	return (1);
**}
**int								round_ccsyl(
**	size_t at,
**	t_s_so *syl,
**	char const *base,
**	char *overflow)
**{
**	int			carry;
**	char		prv;
**	int			rel;
**
**	if (at >= syl->len)
**		return (0);
**	prv = at ? syl->cc[at - 1] : *overflow;
**	carry = 0;
**	if ((rel = less_eq_more_than_mid(syl->cc[at], base)) == 1 ||
**		(rel == 0 && at && ((has_tail(syl, at, base)) &&
**		(!is_even(prv, base) || prv == *base))))
**		carry = 1;
**	syl->len = at;
**	if (carry && add_carry(base, syl, at, overflow))
**		return (-1);
**	return (1);
**}
*/

void							init_syls(
	enum e_sot type,
	int how_many,
	t_s_so *ar)
{
	t_s_so	init;

	init.len = 0;
	init.type = type;
	init.c = 0;
	if (type == e_sot_cc)
		init.cc = 0;
	while (how_many--)
		*ar++ = init;
}
