#include "ft_printf_inner.h"

long double
	get_ldouble(
		t_s_arg *vaarg)
{
	if (vaarg->type == e_double)
		return (*(double*)vaarg->p_val);
	else if (vaarg->type == e_longdouble)
		return (*(long double*)vaarg->p_val);
	return (NAN);
}

void
	get_fpndfp(
		t_s_arg *g, t_s_fpndfp *ret)
{
	ret->dbl = get_ldouble(g);
	decompose_fpval(g->p_val, g->type, &ret->dec);
}
