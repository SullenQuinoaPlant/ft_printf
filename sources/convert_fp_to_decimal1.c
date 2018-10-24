/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_fp_to_decimal1.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmauvari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 14:50:56 by nmauvari          #+#    #+#             */
/*   Updated: 2018/10/10 18:27:57 by nmauvari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inner.h"

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
