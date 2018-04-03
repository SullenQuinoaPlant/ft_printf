#include "h.h"

static void	(* const f_ar[e_cs_sz])(t_s_pct *) = {
	a_conversion,
	biga_conversion,
	c_conversion,
	d_conversion,
	e_conversion,
	bige_conversion,
	f_conversion,
	bigf_conversion,
	g_conversion,
	bigg_conversion,
	i_conversion,
	n_conversion,
	o_conversion,
	p_conversion,
	s_conversion,
	u_conversion,
	x_conversion,
	bigx_conversion
};

void	output_pct_chk(t_s_pct *chk)
{
	f_ar[chk->convertee->type](chk);
}
