#include "ft_printf_inner.h"

size_t	tssos_outlen(t_s_so stack[], int len)
{
	t_s_so	* const limit = stack + len;
	size_t	ret;

	ret = 0;
	while (stack++ < limit)
		ret += stack->len;
	return (ret);
}

static t_s_so
	init_pad_syllables(
		int *pad_i, t_s_so *syl_ar)
{
	enum e_pad_pos	pp;
	t_s_so			init;

	init = (t_s_so) {0, e_sot_c, {0}};
	init.c = ' ';
	pp = e_pp_left;
	while (pp < e_pp_sz)
		syl_ar[pad_i[pp++]] = init;
	return (init);
}

void
	set_pad_syl(
		t_s_pct *chk, int *pad_i,
		int	syl_count, t_s_so *syl_ar)
{
	size_t		len;
	char		const flags = chk->flags;	
	t_s_so		set;

	
	set = init_pad_syllables(pad_i, syl_ar);
	len = tssos_outlen(syl_ar, syl_count);
	set.len = get_padlen(chk, len);
	if (!set.len)
		;
	else if (flags & MINUS_FLAG)
		syl_ar[pad_i[e_pp_left]] = set;
	else if (flags & ZERO_FLAG)
	{
		set.c = '0';
		syl_ar[pad_i[e_pp_middle]] = set;
	}
	else
		syl_ar[pad_i[e_pp_left]] = set;
}

int
	round_ccsyl(
		size_t at,
		t_s_so *syl,
		char const * base)
{
	if (at >= syl->len)
		return (1);
	syl->len = at;
	if (!at)
		return (-1);
	if (syl->cc[at] >= base[ft_strlen(base) / 2])
		syl->cc[at - 1]++;
	return (0);
}
