#include "ft_printf_inner.h"

void	ca_prefix(int syl, void *p)
{
	t_s_acs	* const stf = (t_s_acs*)p;
	t_s_pct * const chk = stf->chk;
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
	set.cc = stf->prefix + offset;
	stf->syllables[syl] = set;
}

void	ca_power0(int syl, void *p)
{
	t_s_acs	* const stf = (t_s_acs*)p;
	t_s_so	set;

	set.len = 1;
	set.type = e_sot_cc;
	set.cc = &stf->zero;
	stf->zero = stf->fpd.flags & DNORM_F ? '0' : '1';
	stf->syllables[syl] = set;
}

void	ca_separator(int syl, void *p)
{
	t_s_acs	* const stf = (t_s_acs*)p;
	t_s_so	set;
	int*	* const prec = stf->chk->precision;

	set.c = '.';
	set.type = e_sot_c;
	set.len = 0;
	if (stf->chk->flags & HASH_FLAG ||
		(prec && **prec) ||
		(!prec && stf->fpd.aligned))
		set.len = 1;
	stf->syllables[syl] = set;
}

#define MID_BASE 8
void	ca_mantissa(int syl, void *p)
{
	t_s_acs		* const stf = (t_s_acs*)p;
	char const	*r;
	uint64_t	v;
	t_s_so		set;
	int			precise;

	r = stf->chk->flags & BIGCS_FLAG ? g_bhex : g_hex;
	set.len = 0;
	if ((v = stf->fpd.aligned))
		set = syl_lowv_tob(v, r, &stf->m);
	stf->excess = 0;
	if (stf->chk->precision &&
		(precise = **stf->chk->precision) >= 0)
	{
		if (!round_ccsyl((size_t)precise, &set, r))
			stf->excess = (size_t)precise - set.len;
		else if (!precise &&
			*set.cc >= r[MID_BASE])
			stf->zero++;
	}
	stf->syllables[syl] = set;
}
#undef MID_BASE

void	ca_excess_precision(int syl, void *p)
{
	t_s_acs	* stf = (t_s_acs*) p;
	t_s_so	set;

	set.type = e_sot_c;
	set.c = '0';
	if (stf->excess > 0)
		set.len = stf->excess;
	else
		set.len = 0;
	stf->syllables[syl] = set;
}
