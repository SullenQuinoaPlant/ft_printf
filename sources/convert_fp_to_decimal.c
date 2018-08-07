#include "ft_printf_inner.h"

static long double
	log2_to_log10(
		int32_t p2exp)
{
	long double	res;

	res = p2exp;
	res /= M_LN10l;
	res *= M_LN2l;
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

/*this works when you have perfect powers of ten,
**	which I don't.
int
	round_ldouble(
		long double *d, int pow10)
{
	long double	b;
	long double	dd;

	if (!is_finite((b = my_intpowl(10, pow10))))
		return (-1);
	dd = *d / b;
	if (dd - my_floorl(dd) > 0.5)
		*d += b;
	return (0);
}
*/
int
	round_ldouble(
		long double *d, int pow10)
{
	long double	dd;

	if (!is_finite((dd = *d * my_intpowl(10, -pow10))))
		return (-1);
	if (dd - my_floorl(dd) > 0.5)
		*d += my_intpowl(10, pow10);
	return (0);
}
/*So we're going crazy:
void
	round_tspot(
		int roundat, t_s_pot *num)
{
	int			digit;
	long double	d;
	t_s_pot		tmp;

	tmp = *num;
	while (tmp.pow10 > roundat)
	{
		digit = tmp.times;
		tmp.times = (tmp.times - digit) * 10.0;
		d = d / 10.0 + digit;
		
	}
}
*/

int
	trailing_zeros(
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
