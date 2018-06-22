#include "ft_printf_inner.h"

static t_oa
	g_d_outputters = {
		cd_prefix,
		cd_body
};
		
#define S 0
#define PRE 1
#define D 2
static int
	cd_prefix(
		t_s_pct *chk, void *s)
{
	t_s_dcs	* const stf = (t_s_dcs*)s;
	t_s_so	* const syl = stf->syls;

	(void)chk;
	return (output_syllable(&syl[S]));
}

static int
	cd_body(
		t_s_pct *chk, void *s)
{
	t_s_dcs	* const stf = (t_s_dcs*)s;
	t_s_so	* const syl = &stf->syls[PRE];
	int		r;

	//this needs to change, take care of apostrophe in a higher order output function
	if (!(chk->flags & APSTR_FLAG))
		return (output_syllables(syl, D - S));
	r = out_sylinter(&syl[D], (D - S), '.', AF_G);
	return (r);
}

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

static size_t
	set_syls(
		t_s_pct *chk, intmax_t d,
		t_s_dcs *stf)
{
	t_s_so		* const d_so = &stf->syls[D];
	int			pre;

	init_syls(e_sot_c, D_SYLS, stf->syls);
	pre = chk->precision ? **chk->precision : -1;
	if (d || pre)
	{
		*d_so = syl_v_tob(d, g_dec, &stf->b, e_all);
		if (chk->flags & APSTR_FLAG)
			d_so->type = e_sot_apstr_cc;
		if (chk->flags & SPACE_FLAG && d >= 0)
			*d_so->cc = ' ';
		stf->syls[S].c = *d_so->cc++;
		d_so->len--;
		if (d < 0 ||
			(chk->flags & (SPACE_FLAG | PLUS_FLAG)))
			stf->syls[S].len = 1;
		if (pre > 0 && d_so->len - 1 < (size_t)pre &&
			(pre -= d_so->len - 1))
			stf->syls[PRE].len = pre;
	}
	return (syls_outlen(stf->syls, D_SYLS, AF_DG));
}

void		convert_d(t_s_pct *chk)
{
	t_s_dcs		stf;
	size_t		len;
	
	len = set_syls(chk, get_d(chk), &stf);
	g_os.apstr_grp = AF_DG;
	g_os.apstr_pos = apstr_offset(stf.syls[D].len, AF_DG);
	g_os.apstr_c = AF_DS;
	output_padnstuff(len, chk, g_d_outputters, &stf);
}
#undef S
#undef PRE
#undef D
