#include "h.h"

/*base should be a power of 2 between 2 and 64*/
static void	convert_double(char *base, t_s_pct *p_chk)
{
	t_s_dfp		fpd;
	t_s_ib		val;
	t_s_ib		exp;
	t_s_arg		*p_arg;

	p_arg = p_chk->vaarg;
	decompose_fpval(p_arg->p_val, p_arg->type, &fpd);
	if (output_nan_inf(&arg, p_chk))
		return;
	val.len = my_valtobuffer(arg.aligned, base, val.b);
	exp.len = my_valtobuffer(arg.ex, g_dec, exp.b, ALL_SIGNED);
	
	
}

void	
