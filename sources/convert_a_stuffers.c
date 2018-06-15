#include "ft_printf_inner.h"

void	ca_prefix(int syl, void *p)
{
	t_s_acs	* const stf = (t_s_acs*)p;
	t_s_pct * const chk = p->chk;
	int		offset;
	t_s_so	set;

	offset = 0;
	if (stf->fpd.flags & SIGN_F)
		stf->prefix[0] = '-';
	else if (chk->flags & SPACE_FLAG)
		stf->prefix[0] = ' ';
	else if (chk->flags & PLUS_FLAG)
		stf->prefix[0] = '+';
	else
		offset = 1;
	stf->prefix[1] = '0';
	stf->prefix[2] = chk->flags & BIGCS_FLAG ? 'X' : 'x';
	set.len = sizeof(stf->prefix) - offset;
	set.type = e_sot_cc;
	set.cc = &stf->prefix + offset;
	stf->syllables[syl] = set;
}

void	ca_power0(int syl, void *p)
{
	t_s_acs	* const stf = (t_s_acs*)p;
	t_s_so	set;

	set.len = 1;
	set.type = e_sot_c;
	set.c = p->fdp.flags & DNORM_F ? '0' : '1';
	stf->syllables[syl] = set;
}

void	ca_separator(int syl, void *p)
{
	t_s_acs	* const stf = (t_s_acs*)p;
	t_s_so	set;
	int*	* const precision = p->chk->precision;

	set.c = '.';
	set.type = e_sot_c;
	set.len = 0;
	if (stf->chk->flags & HASH_FLAG ||
		(precision && **precision) ||
		(!precision && p->fpd.aligned))
		set.len = 1;
	stf->syllables[syl] = set;
}

void	ca_mantissa(int syl, void *p)
{
	t_s_pct	* const chk = ((t_s_acs*)p)->chk;
	int*	* const pre = ((t_s_acs*)p)->chk->precision;
	t_s_so	set;

	precision = ? **pre : INT_MAX;
	set.type = e_sot_cc;
	digits = my_lowv_tob(
	set.len = 
	else
		set.len = 0;
	stf->syllables[syl] = set;
}
