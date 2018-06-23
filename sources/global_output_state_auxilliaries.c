#include "ft_printf_inner.h"

void
	gos_set_apstr(
		size_t grp, char c, size_t len)
{
	size_t	len;

	g_os.apstr_grp = 0;
	if (grp && c && len)
	{
		g_os.aptsr_grp = grp;
		g_os.aptsr_c = c;
		len = tssos_lensum(first, count);
		g_os.apstr_pos = apstr_offset(len, grp);
	}
}

void
	gos_set_grp(
		t_s_sgd *grp)
{
	g_os.aptsr_grp = grp->apstr_grp;
	g_os.aptsr_pos = grp->apstr_pos;
	g_os.aptsr_c = grp->apstr_c;
}
