#include "ft_printf_inner.h"

int
	out_eat_tspot(
		size_t count, t_s_pot *num)
{
	long double	d;
	int			digit;
	int			r;

	r = -1;
	d = num->times;
	while (count-- && r)
	{
		digit = d;
		r = output_c(1, g_dec_syms[digit]);
		d = (d - digit) * 10.0;
		num->pow10--;
	}
	num->times = d;
}

int
	tsof_out_eat_tspot(
		size_t len, void *arg)
{
	return (out_eat_tspot(len, arg));
}
