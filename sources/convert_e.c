#include "ft_printf_inner.h"

static t_stuffer
	g_fstr[E_SYLLABLES + 1] = {
		dummy_stuffer,
		ce_sign,
		dummy_stuffer,
		ce_power0,
		ce_separator,
		ce_lowpowers,
		ce_excess_precision,
		ce_to_the_power,
		ce_exponent,
		dummy_stuffer,
		0
};

void		convert_e(t_s_pct *p_chk)
{
	(void)p_chk;
}

void		convert_e_big(t_s_pct *p_chk)
{
	p_chk->flags |= BIGCS_FLAG;
	convert_e(p_chk);
}
