#include "inner.h"

static void	(* const f_ar[e_cs_sz])(t_s_pct *) = {
	convert_nospec,
	convert_a,
	convert_a_big,
	convert_b,
	convert_b_big,
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
	t_e_cs	spe;

	f_cpy = p_chk->flags;
	if (f_cpy & MINUS_FLAG || (p_chk->precision &&
		((spe = p_chk->specifier) == e_d || spe == e_i ||
		spe == e_o || spe == e_u || spe == e_x ||
		spe == e_X)))
		f_cpy &= ~(ZERO_FLAG);
	if (f_cpy & PLUS_FLAG)
		f_cpy &= ~(SPACE_FLAG);
	p_chk->flags = f_cpy;
}

static void	filter_width(t_s_pct *p_chk)
{
	int		wd;

	if (!p_chk->width)
		return;
	wd = **p_chk->width;
	if (wd < 0)
	{
		p_chk->flags |= MINUS_FLAG;
		wd = wd == INT_MIN ? -(1 + wd) : -wd;
		**p_chk->width = wd;
	}
}

static void	filter_precision(t_s_pct *chk)
{
	if (chk->precision &&
		**chk->precision < 0 &&
		!(chk->specifier == e_b || chk->specifiel == e_B))
			**chk->precision = 0;
}

void		output_pct_chk(t_s_pct *p_chk)
{
	filter_width(p_chk);
	filter_flags(p_chk);
	filter_precision(p_chk);
	f_ar[p_chk->specifier](p_chk);
}
