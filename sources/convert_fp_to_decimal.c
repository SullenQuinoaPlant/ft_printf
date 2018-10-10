/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_fp_to_decimal.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmauvari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 14:50:56 by nmauvari          #+#    #+#             */
/*   Updated: 2018/10/10 18:27:57 by nmauvari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

/*
**No down rounding because trailing zeroes aren't printed anyways.
*/
#ifdef PRTF_ROUNDING_BEHAVIOR_NEAR_EVEN
static int							is_even(
	long double d)
{
	int		is_even;

	is_even = (my_floorl(d / 2.0L) * 2.0L == d);
	return (is_even);
}

int									round_ldouble(
	long double *d,
	int pow10)
{
	long double	dd;
	long double	ddd;
	long double	floor;

	if (!is_finite((dd = *d * my_intpowl(10, -pow10))))
		return (-1);
	floor = my_floorl(dd);
	if ((ddd = dd - floor) > 0.5 ||
		(ddd == 0.5 && !is_even(floor)))
		*d += my_intpowl(10, pow10);
	return (0);
}
#endif

#ifdef PRTF_ROUNDING_BEHAVIOR_AWAY
int									round_ldouble(
	long double *d,
	int pow10)
{
	long double	dd;

	if (!is_finite((dd = *d * my_intpowl(10, -pow10))))
		return (-1);
	if (dd - my_floorl(dd) >= 0.5)
		*d += my_intpowl(10, pow10);
	return (0);
}
#endif

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
