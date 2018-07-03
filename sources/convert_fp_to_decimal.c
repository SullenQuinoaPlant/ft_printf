#include "convert_fp_to_decimal.h"

static long double
	log2_to_log10(
		int32_t p2exp)
{
	long double	res;

	res = p2exp;
	res /= M_LN10;
	res *= M_LN2;
	return (res);
}

t_s_pot
	near_low_pot(
		long double *d)
{
	t_s_dfp		dec;
	long double	log;
	t_s_pot		ret;

	decompose_ldouble(d, &dec);
	log = log2_to_log10(dec.exp - MANT_RES);
	ret.pow10 = (int)log;
	log -= (int)log;
	ret.times = (*d * powl(2, -dec.exp)) * powl(10, log);
	if (ret.times >= 10.0)
	{
		ret.times /= 10.0;
		ret.pow10++;
	}
	return (ret);
}

int
	round_ldouble(
		long double *d, int pow10)
{
	long double	b;
	long double	dd;

	if (!isfinite((b = powl(10, pow10))))
		return (-1);
	dd = *d / b;
	if (dd - floorl(dd) >= 0.5)
		*d += b;
	return (0);
}
