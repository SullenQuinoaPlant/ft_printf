#include "inner.h"

void	ca_to_the_power(int syl, void *p)
{
	t_s_acs	* const stf = (t_s_acs*)p;
	t_s_so	set;

	set.len = 1;
	set.type = e_sot_c;
	if (stf->chk->flags & BIGCS_FLAG)
		set.c = 'P';
	else
		set.c = 'p';
	stf->syllables[syl] = set;
}

void	ca_exponent(int syl, void *p)
{
	t_s_acs	* stf = (t_s_acs*)p;
	t_s_so	set;

	set = syl_v_tob(stf->fpd.exp, VTB_DEC_SYMS, &stf->e, e_vtb_spall);
	if (stf->chk->flags & APSTR_FLAG)
		set.type = e_sot_apstr_cc;
	stf->syllables[syl] = set;
}
