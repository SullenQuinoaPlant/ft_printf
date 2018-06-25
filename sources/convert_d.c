#include "ft_printf_inner.h"

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
	int		r;

	(void)chk;
	r = output_syllables(&stf->syls[PRE], D - S);
	return (r);
}

static t_oa
	g_d_outputters = {
		cd_prefix,
		cd_body
};
		
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
	if (!d && !pre)
		return (0);
	*d_so = syl_v_tob(d, g_dec, &stf->b, e_all);
	if (chk->flags & APSTR_FLAG)
	{
		d_so->type = e_sot_apstr_cc;
		stf->syls[PRE].type = e_sot_apstr_c;
	}
	if (chk->flags & SPACE_FLAG && d >= 0)
		*d_so->cc = ' ';
	stf->syls[S].c = *d_so->cc++;
	d_so->len--;
	if (d < 0 ||
		(chk->flags & (SPACE_FLAG | PLUS_FLAG)))
		stf->syls[S].len = 1;
	if (pre > 0 && d_so->len < (size_t)pre &&
		(pre -= d_so->len))
		stf->syls[PRE].len = pre;
	return (syls_outlen(stf->syls, D_SYLS, AF_DG));
}

void		convert_d(t_s_pct *chk)
{
	t_s_dcs		stf;
	size_t		len;
	size_t		ap_len;
	
	len = set_syls(chk, get_d(chk), &stf);
	if (chk->flags & APSTR_FLAG &&
		(ap_len = len - stf.syls[S].len))
		gos_set_apstr(AF_DG, AF_DS, ap_len);
	else
		gos_set_apstr(0, 0, 0);
	output_padnstuff(len, chk, g_d_outputters, &stf);
}
#undef S
#undef PRE
#undef D
