#include "convert_fp_to_decimal.h"

static double
	log2_to_log10(
		int32_t p2exp)
{
	double	res;

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
	double		log;
	t_s_pot		ret;

	decompose_ldouble(d, &dec);
	log = log2_to_log10(dec.exp - MANT_RES);
	ret.pow10 = (int)log;
	log -= (int)log;
	ret.times = (*d * pow(2, -dec.exp)) * pow(10, log);
	if (ret.times >= 10.0)
	{
		ret.times /= 10.0;
		ret.pow10++;
	}
	return (ret);
}
