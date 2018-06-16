#include "ft_printf_inner.h"

void	ca_to_the_power(int syl, void *p)
{
	t_s_acs	* const stf = (t_s_acs*)p;
	t_s_so	set;

	set.len = sizeof(stf->midfix);
	set.type = e_sot_cc;
	set.cc = stf->midfix;
	stf->midfix[0] = 'p';
	if (stf->chk->flags & BIGCS_FLAG)
		stf->midfix[0] = 'P';
	stf->midfix[1] = '+';
	if (stf->fpd.flags & SIGN_F)
		stf->midfix[1] = '-';
	stf->syllables[syl] = set;
}

void	ca_exponent(int syl, void *p)
{
	t_s_acs	* stf = (t_s_acs*)p;
	t_s_so	set;

	set = syl_uv_tob(stf->fpd.exp, g_dec, &stf->e);
	stf->syllables[syl] = set;
}
