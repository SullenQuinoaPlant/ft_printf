#include "ft_printf_inner.h"

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
		type == e_sot_apstr_c ||
		type == e_sot_apstr_f)
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
			apstr_zpad_adjust(&syl_ar[i], syl_grps);
	}
	else
		syl_ar[pad_i[e_pp_left]].len = len;
}