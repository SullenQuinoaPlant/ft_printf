/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_fp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmauvari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 12:52:35 by nmauvari          #+#    #+#             */
/*   Updated: 2018/10/09 12:53:04 by nmauvari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inner.h"

int								out_eat_tspot(
	size_t count,
	t_s_pot *num)
{
	long double	d;
	int			digit;
	int			r;

	r = -1;
	d = num->times;
	while (count-- && r)
	{
		digit = d;
		r = output_c(1, VTB_DEC_SYMS[digit]);
		d = (d - digit) * 10.0;
		num->pow10--;
	}
	num->times = d;
	return (r);
}

int								tsof_out_eat_tspot(
	size_t len,
	void *arg)
{
	return (out_eat_tspot(len, arg));
}
