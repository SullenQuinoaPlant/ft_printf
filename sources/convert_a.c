#include "h.h"
static	convert_double(char *base, t_s_pct *p_chk)
{
	t_u_d	arg;
	t_s_ib	val;

	ft_memcpy(&arg.parts, p_chk->convertee->p_arg, sizeof(t_u_d.ar));
	val.len = my_valtobuffer((uintmax_t)arg.mantissa, base, val.b);
	
}
