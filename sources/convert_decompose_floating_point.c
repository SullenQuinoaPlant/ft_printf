#include "ft_printf_inner.h"

# ifdef ARCH_A
/*unused function
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
*/

static void	decompose_double(void const *p_val, t_s_dfp *p_ret)
{
	t_u_d	arg;
	
	ft_memcpy(&arg, p_val, sizeof(double));
	*p_ret = (t_s_dfp){arg.sign, arg.exp - DB_E_BIAS,
						arg.mant, arg.mant << 12};
	if (arg.exp == ~0)
		p_ret->flags |= arg.mant ? NAN_F : INF_F;
	else if (arg.exp == 0)
		p_ret->flags |= arg.sign ? OVER_F : DNORM_F;
	else if (arg.exp)
		p_ret->mant |= 1ull<<52;
}

static void	decompose_ldouble(void const *p_val, t_s_dfp *p_ret)
{
	t_u_ld	arg;
	
	ft_memcpy(&arg, p_val, sizeof(long double));
	*p_ret = (t_s_dfp){arg.sign, arg.exp - LDB_E_BIAS,
						arg.mant, arg.mant << 1};
	if (arg.exp == ~0)
		p_ret->flags |= arg.mant ? NAN_F : INF_F;
	else if (arg.exp == 0)
		p_ret->flags |= arg.sign ? OVER_F : DNORM_F;
}
# endif

void		decompose_fpval(
	void const *p_val,
	t_e_t type,
	t_s_dfp *p_ret)
{
	if (type == e_double)
		decompose_double(p_val, p_ret);
	else if (type == e_longdouble)
		decompose_ldouble(p_val, p_ret);
	else
		*p_ret = (t_s_dfp){0, 0, 0, 0};
}
