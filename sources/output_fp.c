#include "ft_printf_inner.h"

int
	out_eat_tspot(
		size_t count, t_s_pot *num)
{
	long double	d;
	int			digit;
	int			r;

	r = -1;
	while (count-- && r)
	{
		digit = num.times;
		r = output_c(1, g_dec_syms[digit]);
		num->times = (num->times - digit) * 10.0;
		num->pow10--;
	}
}

int
	tsof_out_eat_tspot(
		size_t len, void *arg)
{
	return (out_eat_tspot(len, arg));
}
