#include "ft_printf_inner.h"

void
	gos_set_apstr(
		size_t grp, char c, size_t len)
{
	g_os.apstr_grp = 0;
	if (grp && c && len)
	{
		g_os.apstr_grp = grp;
		g_os.apstr_c = c;
		g_os.apstr_pos = apstr_offset(len, grp);
	}
}

void
	gos_set_grp(
		t_s_sgd *grp)
{
	g_os.apstr_grp = grp->apstr_grp;
	g_os.apstr_pos = grp->apstr_pos;
	g_os.apstr_c = grp->apstr_c;
}

void
	init_output_state(
		int fd)
{
	g_os.output_len = 0;
	g_os.fd = fd;
	g_os.errored = 0;
}
