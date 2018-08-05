#include "libmyfloatingpoint.h"
#include "ft_printf_inner.h"

long double
	get_ldouble(
		t_s_arg *vaarg)
{
	t_e_t	const type = vaarg->type;

	if (type == e_double)
		return (*(double*)vaarg->p_val);
	else if (type == e_longdouble)
		return (*(long double*)vaarg->p_val);
	return (compose_nan());
}

void
	set_dfp(
		t_s_arg	*arg, t_s_dfp *ret)
{
	t_e_t		type;

	type = arg->type;
	if (type == e_double)
		decompose_double(arg->p_val, p_ret);
	else if (type == e_longdouble)
		decompose_ldouble(arg->p_val, p_ret);
	else
		*p_ret = (t_s_dfp){0, 0, 0, 0};
}

void
	get_fpndfp(
		t_s_arg *g, t_s_fpndfp *ret)
{
	ret->dbl = get_ldouble(g);
	set_dfp(g, &ret->dec);
}
