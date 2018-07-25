#include "ft_printf_inner.h"

void		convert_n(t_s_pct *chk)
{
	uintmax_t	const val = g_os.output_len;;
	size_t		sz;
	t_e_t		target;

	target = get_etype(chk->specifier, chk->len_mod);
	sz = g_et_sz[target];
	ft_memcpy(*(void**)chk->vaarg->p_val, &val, sz);
}
