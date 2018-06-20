#include "ft_printf_inner.h"

static void
	filter_flags(
		t_s_pct *chk)
{
	chk->flags &= ~HASH_FLAG;
}

void		convert_d(t_s_pct *chk)
{
	t_s_arg		* const arg = chk->vaarg;
	t_s_dcs		stf;
	intmax_t	d;
	
	ft_memcpy(&(d = 0), arg.p_val, g_etsz[arg.type]);
	stf.syl[0] = syl_v_tob(d, g_dec, b + e_mib_offset, e_all);
	
}
