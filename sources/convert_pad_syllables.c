#include "ft_printf_inner.h"

static void
	init_pad_syllables(
		int *pad_i, t_s_so *syl_ar)
{
	enum e_pad_pos	pp;
	t_s_so			init;
	int				mid_pad;
	t_e_sot			type;

	init.len = 0;
	init.type = e_sot_c;
	init.c = ' ';
	pp = e_pp_left;
	while (pp < e_pp_sz)
		syl_ar[pad_i[pp++]] = init;
	syl_ar[(mid_pad = pad_i[e_pp_middle])].c = '0';
	type = syl_ar[mid_pad + 1].type;
	if ((type = syl_ar[mid_pad + 1].type) == e_sot_apstr_cc ||
		type == e_sot_apstr_c || type == e_sot_apstr_f)
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
	if (!(len = get_padlen(chk, sylgrps_outlen(syl_grps, count))))
		return;
	if (flags & MINUS_FLAG)
		syl_ar[pad_i[e_pp_right]].len = len;
	else if (flags & ZERO_FLAG)
	{
		i = pad_i[e_pp_middle];
		syl_ar[i].len = len;
		if (syl_ar[i].type == e_sot_apstr_c)
			apstrify_zpad_grp(&syl_ar[i], syl_grps);
	}
	else
		syl_ar[pad_i[e_pp_left]].len = len;
}
