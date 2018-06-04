#include "ft_printf_inner.h"

void const	*vaarg_ulonglong(va_list *p_va_l)
{
	t_list				*known_val;
	unsigned long long	val;

	val = va_arg(*p_va_l, unsigned long long);
	if((known_val = ft_lstnew(&val, sizeof(typeof(val)))))
	{
		ft_lstadd(&g_ps.p_known_vals, known_val);
		return (known_val->content);
	}
	else
		g_ps.errored++;
	return (0);
}

void const	*vaarg_longlongptr(va_list *p_va_l)
{
	t_list		*known_val;
	long long	*val;

	val = va_arg(*p_va_l, typeof(val));
	if((known_val = ft_lstnew(&val, sizeof(typeof(val)))))
	{
		ft_lstadd(&g_ps.p_known_vals, known_val);
		return (known_val->content);
	}
	else
		g_ps.errored++;
	return (0);
}

void const	*vaarg_ptrdiff_t(va_list *p_va_l)
{
	t_list		*known_val;
	ptrdiff_t	val;

	val = va_arg(*p_va_l, typeof(val));
	if((known_val = ft_lstnew(&val, sizeof(typeof(val)))))
	{
		ft_lstadd(&g_ps.p_known_vals, known_val);
		return (known_val->content);
	}
	else
		g_ps.errored++;
	return (0);
}

void const	*vaarg_short(va_list *p_va_l)
{
	t_list		*known_val;
	int			val;

	val = va_arg(*p_va_l, typeof(val));
	if((known_val = ft_lstnew(&val, sizeof(typeof(val)))))
	{
		ft_lstadd(&g_ps.p_known_vals, known_val);
		return (known_val->content);
	}
	else
		g_ps.errored++;
	return (0);
}

void const	*vaarg_ushort(va_list *p_va_l)
{
	t_list		*known_val;
	int			val;

	val = va_arg(*p_va_l, typeof(val));
	if((known_val = ft_lstnew(&val, sizeof(typeof(val)))))
	{
		ft_lstadd(&g_ps.p_known_vals, known_val);
		return (known_val->content);
	}
	else
		g_ps.errored++;
	return (0);
}
