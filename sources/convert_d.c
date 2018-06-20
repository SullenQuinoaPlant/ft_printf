#include "ft_printf_inner.h"

#define D 0
#define PRE 1
static void
	set_d(t_s_pct *chk, t_s_dcs *stf)
{
	t_s_arg		* const arg = chk->vaarg;
	t_s_so		* const d_so = &stf->syllables[D];
	intmax_t	d;
	int			pre;

	d = 0;
	ft_memcpy(&d, arg->p_val, g_etsz[arg->type]);
	pre = chk->precision ? **chk->precision : -1;
	if (d || pre)
	{
		*d_so = syl_v_tob(d, g_dec, &stf->b, e_all);
		if (pre > 0 && d_so->len - 1 < (size_t)pre &&
			(pre -= d_so->len - 1))
			stf->syllables[PRE].len = pre;
		if (chk->flags & SPACE_FLAG && d >= 0)
			*d_so->cc = ' ';
		if (d >= 0 &&
			!(chk->flags & (SPACE_FLAG | PLUS_FLAG)))
		{
			d_so->cc++;
			d_so->len--;
		}
	}
}
#undef D
#undef PRE

static int
	cd_body(
		t_s_pct *chk, void *s)
{
	t_s_dcs	* const stf = (t_s_dcs*)s;
	int		r;

	(void)chk;
	r = output_syllables(stf->syllables, D_SYLLABLES);
	return (r);
}

static t_oa
	g_d_outputters = {
		outputter_nop,
		cd_body
};
		
void		convert_d(t_s_pct *chk)
{
	t_s_dcs		stf;
	size_t		len;
	
	init_syls(e_sot_c, D_SYLLABLES, stf.syllables);
	set_d(chk, &stf);
	len = tssos_outlen(stf.syllables, D_SYLLABLES);
	output_padnstuff(len, chk, g_d_outputters, &stf);
}
