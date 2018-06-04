#include "ft_printf_inner.h"

void const	*vaarg_uintmax_t(va_list *p_va_l)
{
	t_list		*known_val;
	uintmax_t	val;

	val = va_arg(*p_va_l, uintmax_t);
	if((known_val = ft_lstnew(&val, sizeof(uintmax_t))))
	{
		ft_lstadd(&g_ps.known_vals, known_val);
		return (known_val->content);
	}
	else
		g_ps.errored++;
	return (0);
}

void const	*vaarg_long(va_list *p_va_l)
{
	t_list	*known_val;
	long	val;

	val = va_arg(*p_va_l, long);
	if((known_val = ft_lstnew(&val, sizeof(long))))
	{
		ft_lstadd(&g_ps.known_vals, known_val);
		return (known_val->content);
	}
	else
		g_ps.errored++;
	return (0);
}

void const	*vaarg_ulong(va_list *p_va_l)
{
	t_list			*known_val;
	unsigned long	val;

	val = va_arg(*p_va_l, unsigned long);
	if((known_val = ft_lstnew(&val, sizeof(unsigned long))))
	{
		ft_lstadd(&g_ps.known_vals, known_val);
		return (known_val->content);
	}
	else
		g_ps.errored++;
	return (0);
}

void const	*vaarg_longptr(va_list *p_va_l)
{
	t_list	*known_val;
	long	*val;

	val = va_arg(*p_va_l, long*);
	if((known_val = ft_lstnew(&val, sizeof(long*))))
	{
		ft_lstadd(&g_ps.known_vals, known_val);
		return (known_val->content);
	}
	else
		g_ps.errored++;
	return (0);
}

void const	*vaarg_longlong(va_list *p_va_l)
{
	t_list		*known_val;
	long long	val;

	val = va_arg(*p_va_l, long long);
	if((known_val = ft_lstnew(&val, sizeof(long long))))
	{
		ft_lstadd(&g_ps.known_vals, known_val);
		return (known_val->content);
	}
	else
		g_ps.errored++;
	return (0);
}
