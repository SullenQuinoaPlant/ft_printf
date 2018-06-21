#include "ft_printf_inner.h"

t_stuffer	g_fstr[A_SYLLABLES + 1] = {
	dummy_stuffer,
	ca_prefix,
	dummy_stuffer,
	ca_power0,
	ca_separator,
	ca_mantissa,
	ca_excess_precision,
	ca_to_the_power,
	ca_exponent,
	dummy_stuffer,
	0
};

void		convert_a(t_s_pct *chk)
{
	int			* const pads = (int[e_pp_sz]){0};
	t_s_acs		stf;
	t_s_so		*zpad;
	

	stf.chk = chk;
	set_dfp(chk, &stf.fpd);
	if (output_nan_inf(&stf.fpd, chk))
		return;
	stuff_stuff(g_fstr, &stf, pads);
	set_pad_syl(chk, pads, stf.syl_groups, A_SYLLABLES);
	out_syl_groups
	//output_syllables(stf.syllables, A_SYLLABLES);
}

void		convert_a_big(t_s_pct *p_chk)
{
	p_chk->flags |= BIGCS_FLAG;
	convert_a(p_chk);
}
