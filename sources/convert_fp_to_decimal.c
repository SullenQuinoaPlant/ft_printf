#include "convert_fp_to_decimal.h"

/*
static t_s_mmpi
	pow2_bounds(
		t_s_dfp *fpd)
{
	t_s_mmpi	ret;

	ret.min = fpd->exp - 63;
	ret.max = fpd->exp;
	return  (ret);
}
*/

static int32_t
	near_low_10p(
		int32_t p2exp)
{
	int		sign;
	int32_t	lowlog10;

	sign = 0;
	if (p2exp)
		sign = p2exp < 0 ? -1 : 1;
	p2exp *= sign;
	lowlog10 = p2exp / 4;
	while (3 * lowlog10 < p2exp)
		lowlog10++;
	lowlog10 -= sign > 0 ? 1 : 0;
	lowlog10 *= sign;
	return (lowlog10);
}

t_s_pot
	near_low_pot(
		long double *d)
{
	t_s_dfp		dec;
	long double	log;

	decompose_ldouble(d, &dec);
	log = near_low_10p(dec.exp - MANT_RES);
	(void)log;
	return ((t_s_pot){0, 0});
}
