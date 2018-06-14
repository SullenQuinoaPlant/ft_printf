#include "ft_printf_inner.h"

t_stuffer	g_fstr[A_SYLLABLES + 1] = {
	dummy_stuffer,
	ca_prefix,
	dummy_stuffer,
	ca_power0,
	ca_separator,
	ca_mantissa,
	ca_exponent,
	dummy_stuffer,
	0
};

void		convert_a(t_s_pct *chk)
{
	int			* const pad_i = (int[e_pp_sz]){0};
	t_s_acs		stf;
	

	stf.chk = chk;
	set_dfp(chk, &stf.fpd);
	if (output_nan_inf(&stf.fpd, chk))
		return;
	stuff_stuff(g_fstr, &stf, pad_i);
	set_syllable_padding(chk, pad_i, stf.syllables);
	output_syllables(&stf.syllables, A_SYLLABLES);
}

void		convert_a_big(t_s_pct *p_chk)
{
	p_chk->flags |= BIGCS_FLAG;
	convert_a(p_chk);
}
