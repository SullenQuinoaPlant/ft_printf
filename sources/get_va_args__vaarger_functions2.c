#include "inner.h"

void const	*vaarg_longdouble(va_list *p_va_l)
{
	t_list		*known_val;
	long double	val;

	val = va_arg(*p_va_l, long double);
	if((known_val = ft_lstnew(&val, sizeof(long double))))
	{
		ft_lstadd(&g_ps.p_known_vals, known_val);
		return (known_val->content);
	}
	else
		g_ps.errored++;
	return (0);
}

void const	*vaarg_int(va_list *p_va_l)
{
	t_list	*known_val;
	int		val;

	val = va_arg(*p_va_l, int);
	if((known_val = ft_lstnew(&val, sizeof(int))))
	{
		ft_lstadd(&g_ps.p_known_vals, known_val);
		return (known_val->content);
	}
	else
		g_ps.errored++;
	return (0);
}

void const	*vaarg_uint(va_list *p_va_l)
{
	t_list			*known_val;
	unsigned int	val;

	val = va_arg(*p_va_l, unsigned int);
	if((known_val = ft_lstnew(
		&val, sizeof(unsigned int))))
	{
		ft_lstadd(&g_ps.p_known_vals, known_val);
		return (known_val->content);
	}
	else
		g_ps.errored++;
	return (0);
}

void const	*vaarg_intptr(va_list *p_va_l)
{
	t_list	*known_val;
	int		*val;

	val = va_arg(*p_va_l, int*);
	if((known_val = ft_lstnew(&val, sizeof(int*))))
	{
		ft_lstadd(&g_ps.p_known_vals, known_val);
		return (known_val->content);
	}
	else
		g_ps.errored++;
	return (0);
}

void const	*vaarg_intmax_t(va_list *p_va_l)
{
	t_list		*known_val;
	intmax_t	val;

	val = va_arg(*p_va_l, intmax_t);
	if((known_val = ft_lstnew(&val, sizeof(intmax_t))))
	{
		ft_lstadd(&g_ps.p_known_vals, known_val);
		return (known_val->content);
	}
	else
		g_ps.errored++;
	return (0);
}
