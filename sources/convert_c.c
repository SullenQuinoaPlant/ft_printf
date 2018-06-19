#include "ft_printf_inner.h"

static void
	filter_flags(t_s_pct *chk)
{
	chk->flags &= MINUS_FLAG;
}

void		convert_c(t_s_pct *chk)
{
	wint_t	c;
	size_t	lens[e_oi_sz];
	char	ar[UTF8_MAX_CHARS];

	lens[e_prefix] = 0;
	if (chk->vaarg->type == e_wint_t)
	{
		if ((c = *(wint_t*)chk->vaarg->p_val) < 0)
			lens[e_root] = 0;
		else
			lens[e_root] = true_utf8seq(c, ar);
	}
	else
	{
		*ar = *(unsigned char*);
		lens[e_root] = 1;
	}
	output_padnbuffer(ar, lens, chk);
}
