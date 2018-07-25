#include "ft_printf_inner.h"

void		convert_n(t_s_pct *chk)
{
	uintmax_t	const val = g_os.output_len;;
	t_e_t		target;

	target = get_etype(chk->specifier, chk->len_mod);
	ft_memcpy(*(void**)chk->vaarg->p_val, &val, target);
}
