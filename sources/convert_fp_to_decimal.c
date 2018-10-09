/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_fp_to_decimal.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmauvari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 14:50:56 by nmauvari          #+#    #+#             */
/*   Updated: 2018/10/09 16:27:41 by nmauvari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_fp_to_decimal.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmauvari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 12:55:14 by nmauvari          #+#    #+#             */
/*   Updated: 2018/10/09 14:50:49 by nmauvari         ###   ########.fr       */
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

t_s_pot								near_low_pot(
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

static void							round_idontunderstandwhythisis(
	long double *p)
{
	double	d;

	d = *p;
	d += 0.5;
	*p = (int)d;
	if ((int)d == d && (int)d % 2)
		*p -= 1;
}

int									round_ldouble(
	long double *d,
	int pow10)
{
	long double	dd;

	if (!is_finite((dd = *d * my_intpowl(10, -pow10))))
		return (-1);
	if (dd - my_floorl(dd) > 0.5)
		*d += my_intpowl(10, pow10);
	return (0);
}

int									round_ldouble_weird(
	long double *d,
	int pow10)
{
	double	dd;

	if (pow10 == 0 && (dd = *d) > 1.0 && dd < 10.0)
		round_idontunderstandwhythisis(d);
	else
		round_ldouble(d, pow10);
	return (0);
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
