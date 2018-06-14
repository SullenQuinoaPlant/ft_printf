#include "ft_printf_inner.h"

void		convert_f(t_s_pct *p_chk)
{
	(void)p_chk;
}

void		convert_f_big(t_s_pct *p_chk)
{
	(void)p_chk;
}

/*use this and compare with a_conversion:
- syllables for number bits
- padnstuf for padding
- t_sgb in stuff to differentiate body and prefix
- t_oa t_outputter_array in this file to store pointers to the equivalent of the following:


static int	ca_prefix(t_s_pct *p_chk, void *p_stf)
{
	t_s_acs	* const stf = (t_s_acs*)p_stf;
	t_s_so	*strt;
	int		count;

	strt = stf->syllables;
	count = stf->sgb[e_prefix];
	return (output_syllables(strt, count));
}

static int	ca_body(t_s_pct *p_chk, void *p_stf)
{
	t_s_acs	* const stf = (t_s_acs*)p_stf;
	t_s_so	*strt;
	int		count;

	strt = &stf->syllables[sgb[e_prefix]];
	count = stf->sgb[e_root] - stf->sgb[e_prefix];
	return (output_syllables(strt, count));
}
*/
