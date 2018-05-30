#include "ft_printf.h"

static void	ca_prefix(t_s_pct *p_chk, void *stf)
{
	int				const l = 3;
	char			prefix[l] = {0 ,'0', 0};
	int				offset;
	unsigned int	len;
	
	offset = 1;
	if (stf->s.len)
	{
		prefix[0] = stf->s.b;
		offset = 0;
	}
	prefix[2] = p_chk->flags & BIGCS_FLAG ? 'X' : 'x';
	len = l - offset;
	return (gos_update(
		write(g_os.out_stream, prefix + offset, len),
		len));
}

static void	ca_body(t_s_pct *p_chk, void *stf)
{
	int		const out = g_os.out_stream;
	char	* const m = stf->m.b + e_mib_offset - stf->m.len + 1;
	char	* const e = stf->e.b + e_mib_offset - stf->e.len + 1;
	char	const p = p_chk->flags & BIGCS_FLAG ? 'P' : 'p';

	if (gos_update(write(out, &stf->zero, 1)) &&
		stf->sep && gos_update(write(out, &stf->sep, 1)) &&
		stf->m.len &&
		gos_update(write(out, m, stf->m.len)))
		;
	if (gos_update(write(out, &p, 1)) &&
		gos_update(write(out, e, stf->e.len)))
		;
}

void		a_conversion(t_s_pct *p_chk)
{
	t_outputter const	fs[e_oi_sz] = {ca_prefix, ca_body};
	t_s_dfp		fpd;
	t_s_acs		stf;
	t_s_arg		*p_arg;
	size_t		len;

	p_arg = p_chk->vaarg;
	decompose_fpval(p_arg->p_val, p_arg->type, &fpd);
	if (output_nan_inf(&arg, p_chk))
		return;
	len = ft_strlen("0x1p");
	len += sign_to_b(fpd.flags & SIGN_F ? -1 : 1, p_chk, &stf.s);
	stf.zero = fpd.flags & DNORM_F ? '0' : '1';
	stf.sep = fpd.aligned || p_chk->flags & HASH_FLAG ? '.' : 0;
	len += stf.sep ? 1 : 0;
	len += my_lowv_tob(fpd.aligned, g_hex, &stf.m);
	len += my_v_tob(fpd.exp, g_dec, &stf.e, e_all_sign);
	output_padnstuff(len, p_chk, fs, &stf);
}

void		biga_conversion(t_s_pct *p_chk)
{
	p_chk->flags |= BIGCS_FLAG;
	a_conversion(p_chk);
}
