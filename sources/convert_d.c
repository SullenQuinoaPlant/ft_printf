#include "ft_printf_inner.h"

static intmax_t
	get_d(t_s_pct *chk)
{
	t_s_arg		* const arg = chk->vaarg;
	intmax_t	d;
	size_t		dsz;

	dsz = g_etsz[arg->type];
	d = 0;
	ft_memcpy(&d, arg->p_val, dsz);
	if (d & (((intmax_t)1) << ((CHAR_BIT * dsz) - 1)))
		d |= ~((intmax_t)0) << (CHAR_BIT * dsz);
	return (d);
}

#define S 0
#define D 1
#define PRE 2
static size_t
	set_syls(
		t_s_pct *chk, intmax_t d,
		t_s_dcs *stf)
{
	t_s_so		* const d_so = &stf->syllables[D];
	int			pre;

	init_syls(e_sot_c, D_SYLLABLES, stf->syllables);
	pre = chk->precision ? **chk->precision : -1;
	if (d || pre)
	{
		*d_so = syl_v_tob(d, g_dec, &stf->b, e_all);
		if (pre > 0 && d_so->len - 1 < (size_t)pre &&
			(pre -= d_so->len - 1))
			stf->syllables[PRE].len = pre;
		if (chk->flags & SPACE_FLAG && d >= 0)
			*d_so->cc++ = ' ';
		d_so->len--;
		stf->syllables[S].c = *d_so->cc;
		if (d < 0 ||
			(chk->flags & (SPACE_FLAG | PLUS_FLAG)))
			stf->syllables[S].len = 1;
	}
	return (tssos_outlen(stf->syllables, D_SYLLABLES));
}

static int
	cd_body(
		t_s_pct *chk, void *s)
{
	t_s_dcs	* const stf = (t_s_dcs*)s;
	t_s_so	* const syl = stf->syllables;
	int		r;

	if (!(chk->flags & APSTR_FLAG))
		return (output_syllables(syl, D_SYLLABLES));
	r = output_syllable(syl[S])
	r &= out_sylinter(&syl[D], (PRE - S), '.', THSD);
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
	
	len = set_syls(chk, get_d(chk), &stf);
	len += apstr_len(len - stf.syllables[S].len, chk);
	output_padnstuff(len, chk, g_d_outputters, &stf);
}
#undef S
#undef D
#undef PRE
