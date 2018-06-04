#include "ft_printf_inner.h"

static void	(* const f_ar[e_cs_sz])(t_s_pct *) = {
	convert_a,
	convert_a_big,
	convert_c,
	convert_d,
	convert_e,
	convert_e_big,
	convert_f,
	convert_f_big,
	convert_g,
	convert_g_big,
	convert_i,
	convert_n,
	convert_o,
	convert_p,
	convert_s,
	convert_u,
	convert_x,
	convert_x_big
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
	int		width;

	width = **p_chk->width;
	if (width < 0)
	{
		p_chk->flags |= MINUS_FLAG;
		width = width == INT_MIN ? -(width + 1) : -width;
	}
}

void		output_pct_chk(t_s_pct *p_chk)
{
	filter_width(p_chk);
	filter_flags(p_chk);
	f_ar[p_chk->vaarg->type](p_chk);
}
