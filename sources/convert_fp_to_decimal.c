#include "floating_point_bit_patterns.h"

t_s_mmpi
	pow2_bounds(
		t_s_dfp *fpd)
{
	t_s_mmpi	ret;

	ret.min = fpd->exp - 63;
	ret.max = fpd->exp;
	return  (ret);
}

int
	near_low_10p(
		int32_t p2exp)
{
	int 	const sign = p2exp < 0 ? -1 : 1;
	int32_t	i;
	int32_t	j;
	int32_t	p10exp;

	p2exp *= sign;
	i = 0;
	p10exp = 0;
	while (4 * (i + 1) < p2exp)
	{
		p10exp
		i++;
	
	

}
