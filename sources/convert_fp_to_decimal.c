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
		t_s_fpndfp const *num)
{
	long double	log;
	t_s_pot		ret;

	if (num->dbl == 0.0)
		return ((t_s_pot){0, 0.0L});
	log = log2_to_log10(num->dec.exp - MANT_RES);
	ret.pow10 = (int)log;
	log -= (int)log;
	ret.times = num->dbl;
	ret.times *= powl(2, MANT_RES - num->dec.exp);
	ret.times *= powl(10, log);
	while (ret.times < 1.0)
	{
		ret.times *= 10.0;
		ret.pow10--;
	}
	while (ret.times >= 10.0)
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
