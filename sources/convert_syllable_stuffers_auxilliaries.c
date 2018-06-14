#include "ft_printf_inner.h"

static t_s_so
	init_pad_syllables(
		int *pad_i, t_s_so *syl_ar)
{
	e_pad_pos	pp;
	t_s_so		init;

	init = (t_s_so) {0, e_sot_c};
	init.c = ' ';
	pp = e_pp_left;
	while (pp < e_pp_sz)
		syl_ar[pad_i[pp++]] = init;
	return (init);
}

void
	set_pct_pad_syllables(
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
