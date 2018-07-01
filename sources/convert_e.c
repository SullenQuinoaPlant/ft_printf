#include "ft_printf_inner.h"

static t_stuffer
	g_fstr[E_SYLLABLES + 1] = {
		ce_sign,
		ce_separator,
		ce_to_the_power,
		ce_exponent,
		0
};

static t_oa
	g_d_outputters = {
		ce_prefix,
		ce_body
};

#define SIGN_SYL 0
#define SEP_SYL 1
#define E_SYL 2
#define	E_SIGN_SYL 3
#define E_PAD_SYL 4
#define EXP_SYL 5
static void
	set_number(
		t_s_arg *vaarg, t_s_ecs *stf)
{
	long double	d;

	d = get_ldouble(vaarg);
	stf->number = near_low_pot(&d);
}
		
void		convert_e(t_s_pct *p_chk)
{
	t_s_ecs	stf;

	stf.chk = p_chk;
	set_number(p_chk->vaarg, &stf);
	stuff_stuff(g_fstr, &stf, 0);
}
#undef SIGN_SYL
#undef SEP_SYL
#undef E_SYL
#undef E_SIGN_SYL
#undef E_PAD_SYL
#undef EXP_SYL

void		convert_e_big(t_s_pct *p_chk)
{
	p_chk->flags |= BIGCS_FLAG;
	convert_e(p_chk);
}
