/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_vaarged_floatingpoint.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmauvari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 13:19:56 by nmauvari          #+#    #+#             */
/*   Updated: 2018/10/09 13:20:40 by nmauvari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmyfloatingpoint.h"
#include "inner.h"

long double							get_ldouble(
	t_s_arg *vaarg)
{
	t_e_t	const type = vaarg->type;

	if (type == e_double)
		return (*(double*)vaarg->p_val);
	else if (type == e_longdouble)
		return (*(long double*)vaarg->p_val);
	return (compose_nan());
}


void								set_dfp(
	t_s_arg	*arg,
	t_s_dfp *ret)
{
	t_e_t		type;

	type = arg->type;
	if (type == e_double)
		decompose_double(arg->p_val, ret);
	else if (type == e_longdouble)
		decompose_ldouble(arg->p_val, ret);
	else
		*ret = (t_s_dfp){0, 0, 0};
}


void								get_fpndfp(
	t_s_arg *g,
	t_s_fpndfp *ret)
{
	ret->dbl = get_ldouble(g);
	decompose_ldouble(&ret->dbl, &ret->dec);
}
