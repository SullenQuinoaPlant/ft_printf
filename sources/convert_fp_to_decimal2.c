#include "inner.h"

static long double					log2_to_log10(
	int32_t p2exp)
{
	long double	res;

	res = p2exp;
	res /= M_LN10L;
	res *= M_LN2L;
	return (res);
}

#define SMALL_NUMBER (long double)UINT64_MAX
static int							small_number(
	t_s_fpndfp const *num,
	t_s_pot *ret)
{
	int const	sign = num->dbl < 0 ? -1 : 1;
	int			pow10;
	long double	d;

	if ((d = sign * num->dbl) > SMALL_NUMBER)
		return (0);
	pow10 = 0;
	if (d < 1)
		while (d < 1)
		{
			d *= 10.0L;
			pow10--;
		}
	else
		while (d > 10)
		{
			d /= 10.0L;
			pow10++;
		}
	ret->pow10 = pow10;
	ret->times = d;
	return (1);
}

t_s_pot								near_low_pot(
	t_s_fpndfp const *num)
{
	long double	log;
	t_s_pot		ret;

	if (num->dbl == 0.0)
		return ((t_s_pot){0, 0.0L});
	if (small_number(num, &ret))
		return (ret);
	log = log2_to_log10(num->dec.exp);
	ret.pow10 = (int)log;
	ret.times = make_ldouble(0, num->dec.mant, -MANT_RES);
	ret.times *= my_powl(10, log - ret.pow10);
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
	if (num->dbl < 0)
		ret.times *= -1;
	return (ret);
}

int									trailing_zeros(
	long double d,
	unsigned int skip,
	unsigned int trail)
{
	int		zcount;
	int		digit;

	while (skip--)
		d = (d - (int)d) * 10.0;
	zcount = 0;
	while (trail--)
	{
		digit = (int)d;
		zcount = digit ? 0 : zcount + 1;
		d = (d - digit) * 10.0;
	}
	return (zcount);
}
