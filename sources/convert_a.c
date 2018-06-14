#include "ft_printf_inner.h"

static int	ca_prefix(t_s_pct *p_chk, void *p_stf)
{
	t_s_acs	* const stf = (t_s_acs*)p_stf;
	t_s_so	*strt;
	int		count;

	strt = stf->syllables;
	count = stf->sgb[e_prefix];
	return (output_syllables(strt, count));
}

static int	ca_body(t_s_pct *p_chk, void *p_stf)
{
	t_s_acs	* const stf = (t_s_acs*)p_stf;
	t_s_so	*strt;
	int		count;

	strt = &stf->syllables[sgb[e_prefix]];
	count = stf->sgb[e_root] - stf->sgb[e_prefix];
	return (output_syllables(strt, count));
}

static t_s_dfp
	get_dfp(t_s_pct *chk)
{
	t_s_fpd	ret;
	t_s_arg	*arg;

	arg = chk->vaarg;
	decompose_fpval(arg->p_val, arg->type, &ret);
	return (ret);
}

t_ss	g_stuffers[A_SYLLABLES] = {
	pad_syllable,
	a_prefix,
	pad_syllable,
	a_power0,
	a_separator,
	a_mantissa,
	a_exponent,
	pad_syllable,
	0
};

static t_oa g_ofs = {ca_prefix, ca_body};

void		convert_a(t_s_pct *chk)
{
	t_s_acs		stf;
	

	stf.fpd = get_dfp(chk);
	if (output_nan_inf(&fpd, chk))
		return;
	stuff_syllables(g_stuffers, chk, &stf, pad_pos);
	len = tssos_outlen(stf.syllables, A_SYLLABLES);
	output_padnstuff(len, p_chk, ofs, &stf);
}

void		convert_a(t_s_pct *p_chk)
{
	t_sgb		ofs = {ca_prefix, ca_body};
	t_s_dfp		fpd;
	t_s_acs		stf;
	t_s_arg		*p_arg;
	size_t		len;

	p_arg = p_chk->vaarg;
	decompose_fpval(p_arg->p_val, p_arg->type, &fpd);
	if (output_nan_inf(&fpd, p_chk))
		return;
	len = ft_strlen("0x1p");
	len += sign_to_b(fpd.flags & SIGN_F ? -1 : 1, p_chk, &stf.s);
	stf.zero = fpd.flags & DNORM_F ? '0' : '1';
	stf.sep = fpd.aligned || p_chk->flags & HASH_FLAG ? '.' : 0;
	len += stf.sep ? 1 : 0;
	if (fpd.aligned)
		len += my_lowv_tob(fpd.aligned, g_hex, &stf.m);
	len += my_v_tob(fpd.exp, g_dec, &stf.e, e_all_sign);
	output_padnstuff(len, p_chk, ofs, &stf);
}

void		convert_a_big(t_s_pct *p_chk)
{
	p_chk->flags |= BIGCS_FLAG;
	convert_a(p_chk);
}
