#include "ft_printf.h"

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

static void	filter_flags(t_s_pct *p_chk)
{
	char	f_cpy;

	f_cpy = p_chk->flags;
	if (f_cpy & ZERO_FLAG && f_cpy & MINUS_FLAG)
		f_cpy |= ~(ZERO_FLAG);
	if (f_cpy & SPACE_FLAG && f_cpy & PLUS_FLAG)
		f_cpy |= ~(SPACE_FLAG);
	p_chk->flags = f_cpy;
}

static void	filter_width(t_s_pct *p_chk)
{
	if (p_chk->width < 0)
	{
		p_chk->flags |= MINUS_FLAG;
		p_chk->width = width == INT_MIN ? -(width + 1) : -width;
	}
}

void		output_pct_chk(t_s_pct *p_chk)
{
	filter_width(p_chk);
	filter_flags(p_chk);
	f_ar[p_chk->vaarg->type](p_chk);
}
