#include "ft_printf_inner.h"

int
	control_filedes(
		int *fd)
{
	g_os.fd = *fd;
}
