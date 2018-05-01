#include "h.h"

# ifdef ARCH_A
static void	reverse(unsigned long long this,
					unsigned long long max_mark,
					unsigned long long *p_to_res)
{
	unsigned long long	mark;
	unsigned long long	res;

	res = 0;
	mark = 1;
	while (max_mark)
	{
		res |= max_mark & this ? mark : 0ull;
		mark <<= 1;
		max_mark >>= 1;
	}
	*p_to_res = res;
}

static t_s_dfp	decompose_double(void *p_val)
{
	unsigned long long	const max_mark = 0x1ull << 52;
	size_t	const sz = sizeof(double);
	t_s_dfp	ret;
	t_u_d	arg;
	
	ft_memcpy(&arg, p_val, sz);
	ret = (t_s_dfp){arg.sign, arg.exp, arg.mant, 0};
	reverse(arg.mant, max_mark, &ret.rmant);
	if (arg.exp == ~0)
		ret.flags |= arg.mant ? NAN_F : INF_F;
	else if (arg.exp)
	{
		ret.mant |= max_mark;
		ret.rmant += 1;
	}
	return (ret);
}

t_s_dfp	decompose_ldouble(void *p_val)
{
	unsigned long long	const max_mark = 0x1ull << 63;
	size_t	const sz = sizeof(long double);
	t_s_dfp	ret;
	t_u_ld	arg;
	
	ft_memcpy(&arg, p_val, sz);
	ret = (t_s_dfp){arg.sign, arg.exp, arg.mant, 0};
	reverse(arg.mant, max_mark, &ret.rmant);
	if (arg.exp == ~0)
		ret.flags |= arg.mant ? NAN_F : INF_F;
	return (ret);
}
# endif

t_s_dfp		decompose_fpval(void *p_val, t_e_t type)
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
