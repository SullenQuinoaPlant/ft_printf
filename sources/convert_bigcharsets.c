#include "ft_printf_inner.h"

/*this seems stupid, not going to use it*/
int		wants_bigc(t_s_pct *p_chk)
{
	t_e_cs			we_be_big[] = {e_A, e_E, e_F, e_G, e_X};
	t_e_cs			ref_cs;
	unsigned int	ar_sz;
	unsigned int	i;

	ref_cs = p_chk->specifier;
	ar_sz = sizeof(we_be_big) / sizeof(we_be_big[0]);
	i = -1;
	while (++i < ar_sz)
		if (we_be_big[i] == ref_cs)
			return (1);
	return (0);
}
