#include "ft_printf_inner.h"

#define PREFIX_LEN 3
static int	ca_prefix(t_s_pct *p_chk, void *stf)
{
	char			prefix[PREFIX_LEN] = {0 ,'0', 0};
	int				offset;
	unsigned int	len;
	
	offset = 1;
	if (((t_s_acs*)stf)->s.len)
	{
		prefix[0] = ((t_s_acs*)stf)->s.b;
		offset = 0;
	}
	prefix[2] = p_chk->flags & BIGCS_FLAG ? 'X' : 'x';
	len = PREFIX_LEN - offset;
	return (gos_update(
		write(g_os.fd, prefix + offset, len),
		len));
}
#undef PREFIX_LEN

static int	ca_body(t_s_pct *p_chk, void *p_stf)
{
	t_s_acs	* const stf = (t_s_acs*)p_stf;
	char	* const m = stf->m.b + e_mib_offset - stf->m.len + 1;
	char	* const e = stf->e.b + e_mib_offset - stf->e.len + 1;
	char	const p = p_chk->flags & BIGCS_FLAG ? 'P' : 'p';
	int		r;

	r = gos_update(write(g_os.fd, &stf->zero, 1), 1);
	r |= gos_update(write(g_os.fd, &stf->sep, 1), 1);
	r |= gos_update(write(g_os.fd, m, stf->m.len), stf->m.len);
	r |= gos_update(write(g_os.fd, &p, 1), 1);
	r |= gos_update(write(g_os.fd, e, stf->e.len), stf->e.len);
	return (r);
}

void		convert_a(t_s_pct *p_chk)
{
	t_outputter const	fs[e_oi_sz] = {ca_prefix, ca_body};
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
	len += my_lowv_tob(fpd.aligned, g_hex, &stf.m);
	len += my_v_tob(fpd.exp, g_dec, &stf.e, e_all_sign);
	output_padnstuff(len, p_chk, fs, &stf);
}

void		bigconvert_a(t_s_pct *p_chk)
{
	p_chk->flags |= BIGCS_FLAG;
	convert_a(p_chk);
}
