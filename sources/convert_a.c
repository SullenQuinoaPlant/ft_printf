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

static void	set_syl_grps(t_s_acs *stf)
{
	t_s_so	* const syls = stf->syllables;
	t_s_sgd	ar[A_SYLGRPS] = {
			{&syllables[0], 2, 0, 0, '\0'},
			{&syllables[2], 2, 2, 1, '_'},
			{&syllables[4], 1, 0, 0, '\0'},
			{&syllables[5], 2, 2, 0, '_'},
			{&syllables[7], 1, 0, 0, '\0'},
			{&syllables[8], 1, 3, 0, '\''}};

	ft_memcpy(stf->syl_groups, ar, sizeof(ar));
}

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
	out_syl_groups(stf.syl_groups, A_SYLGRSPS);
}

void		convert_a_big(t_s_pct *p_chk)
{
	p_chk->flags |= BIGCS_FLAG;
	convert_a(p_chk);
}
