#include "h.h"

# ifdef ARCH_A
static reverse(unsigned long long this,
					unsigned long long max_mark,
					unsigned long long p_to_res)
{
	unsigned long long	mark;
	unsigned long long	res;

	res = 0;
	mark = 0x01ull;
	while (mark <= max_mark)
	{
		res <<= 1;
		res += mark & this ? 1 : 0;
		mark <<= 1;
	}
	*p_to_res = res;
}

static t_s_dfp	decompose_double(void *p_val)
{
	size_t	const sz = sizeof(double);
	t_s_dfp	ret;
	t_u_d	arg;
	
	ft_memcpy(&arg, p_chk->vaarg->p_arg, sz);
	ret = (t_s_dfp){arg.sign, arg.exp, 0};
	reverse(arg.mant, max_mark, &ret.mant);
	if (arg.exp == ~0)
	{
		if (arg.mant)
			ret.flags |= NAN_F;
		else
			ret.flags |= INF_F;
	}
	return (ret);
}

t_s_dfp	decompose_ldouble(void *p_val)
{
	unsigned long long	max_mark = 0x01 << 63;
	size_t	const sz = sizeof(long double);
	t_s_dfp	ret;
	t_u_ld	arg;
	
	ft_memcpy(&arg, p_chk->vaarg->p_arg, sz);
	ret = (t_s_dfp){arg.sign, arg.exp, 0};
	reverse(arg.mant, max_mark, &ret.mant);
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
