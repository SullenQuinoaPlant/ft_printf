#include "h.h"

static void	convert_double(char *base, t_s_pct *p_chk)
{
	t_u_d	arg;
	t_s_ib	val;
	t_s_ib	exp;

	ft_memcpy(&arg, p_chk->vaarg->p_arg, sizeof(double));
	if (output_nan_inf(&arg, p_chk))
		return;
	val.len = my_valtobuffer(arg.mant, base, val.b);
	exp.len = my_valtobuffer(arg.ex, g_dec, exp.b);
	
	
}
