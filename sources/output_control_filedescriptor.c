#include "ft_printf_inner.h"

void
	control_filedes(
		int **fd)
{
	g_os.fd = **fd;
}
