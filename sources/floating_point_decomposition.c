#include "ft_printf_inner.h"

#ifdef ARCH_A
/*unused function
static void	reverse(uint64_t this,
					uint64_t max_mark,
					uint64_t *p_to_res)
{
	uint64_t	mark;
	uint64_t	res;

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

void		decompose_double(double const *p_val, t_s_dfp *p_ret)
{
	t_u_d	arg;
	
	ft_memcpy(&arg, p_val, sizeof(double));
	*p_ret = (t_s_dfp){arg.sign, arg.exp - DB_E_BIAS,
				arg.mant, (uint64_t)arg.mant << 12};
	if (arg.exp == ~0)
		p_ret->flags |= arg.mant ? NAN_F : INF_F;
	else if (arg.exp == 0)
	{
		p_ret->flags |= DNORM_F; 
		p_ret->exp += arg.mant ? 1 : DB_E_BIAS;
	}
	else
		p_ret->mant |= 1ull<<52;
}

void		decompose_ldouble(long double const *p_val, t_s_dfp *p_ret)
{
	t_u_ld	arg;
	
	ft_memcpy(&arg, p_val, sizeof(long double));
	*p_ret = (t_s_dfp){arg.sign, arg.exp - LDB_E_BIAS,
						arg.mant, arg.mant << 1};
	if (arg.exp == ~0)
		p_ret->flags |= arg.mant ? NAN_F : INF_F;
	else if (arg.exp == 0)
	{
		p_ret->flags |= DNORM_F;
		p_ret->exp += arg.mant ? 1 : LDB_E_BIAS;
	}
}
#endif
