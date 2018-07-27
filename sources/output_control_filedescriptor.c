#include "ft_printf_inner.h"

static void
	control_filedes(
		int **fd)
{
	g_os.fd = **fd;
}

int
	toctlf_control_filedes(
		void *pp_fd)
{
	control_filedes(pp_fd);
	return (1);
}
