#include "ft_printf_inner.h"

int
	run_output_ctl(
		t_s_ctl *chk)
{
	if (*chk->foo)
		return ((*chk->foo)(chk->p_args));
	return (0);
}
