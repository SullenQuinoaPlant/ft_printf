#include "h.h"

static ssize_t	(* const f_ar[e_cs_sz])(t_s_pct *) = {
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

void			output_pct_chk(t_s_pct *chk)
{
	ssize_t	i;

	i = f_ar[chk->convertee->type](chk);
	if (i < 0)
		g_os.errored++;
	else
		g_os.out_str_len += (size_t)i;
}
