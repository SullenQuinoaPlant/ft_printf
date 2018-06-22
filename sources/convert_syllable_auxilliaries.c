#include "ft_printf_inner.h"

size_t
	syls_outlen(
		t_s_so *syl, int count, size_t apstr_grp)
{
	t_s_so	* const lim = syl + count;
	size_t	total_len;
	size_t	len;
	t_e_sot	type;

	total_len = 0;
	while (syl < lim)
	{
		len = syl->len;
		type = syl->type;
		if (type == e_sot_apstr_cc ||
			type == e_sot_apstr_c)
			len += apstr_len_raw(len, apstr_grp);
		total_len += len;
		syl++;
	}
	return (total_len);
}

size_t	sylgrps_outlen(t_s_sgd grp[], int count)
{
	t_s_sgd	* const lim = grp + count;
	size_t	total_len;
	size_t	len;

	total_len = 0;
	while (grp < lim)
	{
		len = tssos_lensum(grp->first, grp->sz);
		if (grp->apstr_grp)
			len += apstr_len_grp(grp);
		total_len += len;
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

static void
	init_pad_syllables(
		int *pad_i, t_s_so *syl_ar)
{
	enum e_pad_pos	pp;
	t_s_so			init;
	int				mid_pad;
	t_e_sot			type;

	init = (t_s_so) {0, e_sot_c, {0}};
	init.c = ' ';
	pp = e_pp_left;
	while (pp < e_pp_sz)
		syl_ar[pad_i[pp++]] = init;
	mid_pad = pad_i[e_pp_middle];
	type = syl_ar[mid_pad + 1].type;
	if (type == e_sot_apstr_cc ||
		type == e_sot_apstr_c)
		syl_ar[mid_pad].type = e_sot_apstr_c;
}

void
	set_pad_syl(
		t_s_pct *chk, int *pad_i,
		t_s_sgd *syl_grps, int count)
{
	t_s_so		* const syl_ar = syl_grps->first;
	char		const flags = chk->flags;	
	size_t		len;
	int			i;

	
	init_pad_syllables(pad_i, syl_ar);
	len = sylgrps_outlen(syl_grps, count);
	len = get_padlen(chk, len);
	if (!len)
		return;
	if (flags & MINUS_FLAG)
		syl_ar[pad_i[e_pp_left]].len = len;
	else if (flags & ZERO_FLAG)
	{
		i = pad_i[e_pp_middle];
		syl_ar[i].c = '0';
		syl_ar[i].len = len;
		if (syl_ar[i].type == e_sot_apstr_c)
			apstr_pad_adjust(&syl_ar[i], syl_grps);
	}
	else
		syl_ar[pad_i[e_pp_left]].len = len;
}

/*had to change rounding policy to accomodate printf,
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
**
**	... to what can now be found below.
*/
int
	round_ccsyl(
		size_t at,
		t_s_so *syl,
		char const * base,
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
