#include "h.h"

int		wants_bigc(t_s_pct *p_chk)
{
	t_e_cs	we_be_big[] = {e_A, e_E, e_F, e_G, e_X};
	t_e_cs	ref_cs;
	int	 	i;

	ref_cs = p_chk->specifier;
	i = -1;
	while (++i < sizeof(we_be_big) / sizeof(we_be_big[0]))
		if (we_be_big[i] == ref_cs)
			return (1);
	return (0);
}
