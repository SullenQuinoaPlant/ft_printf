#include "h.h"

# ifdef A
static t_s_dfp	decompose_double(void *p_val)
{
	size_t	const sz = sizeof(double);
	t_s_dfp	ret;
	t_u_d	arg;
	
	ft_memcpy(&arg, p_chk->vaarg->p_arg, sz);
	ret = (t_s_dfp){arg.sign, arg.exp, arg.mant};
	if (arg.exp = ~0)
	{
		if (arg.mant)
			ret.flags |= NAN_F;
		else
			ret.flags |= INF_F;
	}
	return (ret);
}

static t_s_dfp	decompose_ldouble(void *p_val)
{
	size_t	const sz = sizeof(long double);
	t_s_dfp	ret;
	t_u_ld	arg;
	
	ft_memcpy(&arg, p_chk->vaarg->p_arg, sz);
	ret = (t_s_dfp){arg.sign, arg.exp, arg.mant};
	if (arg.exp = ~0)
	{
		if (arg.mant)
			ret.flags |= NAN_F;
		else
			ret.flags |= INF_F;
	}
	return (ret);
}
# endif

t_s_dfp		decompose_fpval(void *p_val, t_e_t typ)
{
	t_s_dfp	ret;

	if (type == e_double)
		ret = decompose_double(p_val);
	else if (type == e_longdouble)
		ret = decompose_ldouble(p_val);
	else
		ret = (t_s_dfp){0,0,0};
	return (ret);
}
