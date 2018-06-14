#include "ft_printf_inner.h"

#define PREFIX_LEN 3
static int	ca_prefix(t_s_pct *p_chk, void *stf)
{
	char			prefix[PREFIX_LEN] = {0 ,'0', 0};
	t_s_cc			out;
	
	prefix[0] = ((t_s_acs*)stf)->s;
	out.len = prefix[0] ? PREFIX_LEN : PREFIX_LEN - 1;
	prefix[2] = p_chk->flags & BIGCS_FLAG ? 'X' : 'x';
	return(output(out));
}
#undef PREFIX_LEN

static int	ca_body(t_s_pct *p_chk, void *p_stf)
{
	t_s_acs	* const stf = (t_s_acs*)p_stf;
	int		i;

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
