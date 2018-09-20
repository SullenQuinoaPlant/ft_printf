/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_syllable_auxilliaries.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmauvari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 23:23:02 by nmauvari          #+#    #+#             */
/*   Updated: 2018/09/20 23:31:30 by nmauvari         ###   ########.fr       */
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

/*
**had to change rounding policy to accomodate printf,
**which rouds as follows:
**		0.8 -> 1	(precision 0)
**		0.80 -> 0	(precision 0)
**	which I think is unintuitive.
**Worse, it then gives:
**		0.88 -> 0.8	(precision 1)
**		where it should give 0.9 to be coherent with
**		the previous whacky behavior
**	Anyways, had to change:
**
**	up = 0;
**	if (syl->cc[at] > mid)
**		up = 1;
**	else if (syl->cc[at] == mid)
**	{
**		zero = base[0];
**		i = syl->len - 1;
**		while (i > at && syl->cc[i] == zero)
**			i--;
**		if (i != at)
**			up = 1;
**	}
**	... to what can now be found below.
**			(which I hate)
*/

int								round_ccsyl(
	size_t at,
	t_s_so *syl,
	char const *base,
	char *overflow)
{
	char	mid;
	char	zero;
	int		up;
	size_t	i;

	if (at >= syl->len)
		return (0);
	mid = base[ft_strlen(base) / 2];
	if (syl->cc[at] < mid)
		up = 0;
	else if (syl->cc[at] == mid)
	{
		zero = base[0];
		i = syl->len - 1;
		up = at > 0 ? 0 : 1;/*which is mighty stupid*/
		while (i > at)
			if ((up = syl->cc[i--] != zero))
				break;
	}
	syl->len = at;
	if (up)
	{
		if (at)
			syl->cc[at - 1]++;
		else if (overflow)
			(*overflow)++;
	}
	return (at ? 1 : -1);
}

void
	init_syls(
		enum e_sot type, int how_many, t_s_so *ar)
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
