#include "ft_printf_inner.h"

static t_e_t
	g_target_et[e_lm_sz] = {
		e_int,
		e_char,
		e_short,
		e_long,
		e_longlong,
		e_int,
		e_intmax_t,
		e_size_t,
		e_ptrdiff_t
};

void		convert_n(t_s_pct *chk)
{
	uintmax_t	const val = g_os.output_len;;
	size_t		sz;

	sz = g_et_sz[g_target_et[chk->len_mod]];
	ft_memcpy(*(void**)chk->vaarg->p_val, &val, sz);
}
