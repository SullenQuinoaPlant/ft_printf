#include "ft_printf_inner.h"

int
	is_nan(
		t_s_dfp *dbl)
{
	if (dbl->flags & NAN_F)
		return (1);
	return (0);
}

int
	is_inf(
		t_s_dfp *dbl)
{
	if (dbl->flags & INF_F)
		return (1);
	return (0);
}

int
	is_overf(
		t_s_dfp *dbl)
{
	if (dbl->flags & OVER_F)
		return (1);
	return (0);
}

int
	is_dnorm(
		t_s_dfp *dbl)
{
	if (dbl->flags & DNORM_F)
		return (1);
	return (0);
}
