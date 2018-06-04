#include "ft_printf_inner.h"

void const	*vaarg_shortptr(va_list *p_va_l)
{
	t_list		*known_val;
	short		*val;

	val = va_arg(*p_va_l, typeof(val));
	if((known_val = ft_lstnew(&val, sizeof(typeof(val)))))
	{
		ft_lstadd(&g_ps.known_vals, known_val);
		return (known_val->content);
	}
	else
		g_ps.errored++;
	return (0);
}

void const	*vaarg_size_t(va_list *p_va_l)
{
	t_list		*known_val;
	size_t		val;

	val = va_arg(*p_va_l, typeof(val));
	if((known_val = ft_lstnew(&val, sizeof(typeof(val)))))
	{
		ft_lstadd(&g_ps.known_vals, known_val);
		return (known_val->content);
	}
	else
		g_ps.errored++;
	return (0);
	void const	*p_ret;

	p_ret = &va_arg(*p_va_l, size_t);
	return (p_ret);
}

void const	*vaarg_ssize_t(va_list *p_va_l)
{
	t_list		*known_val;
	ssizet_t	val;

	val = va_arg(*p_va_l, typeof(val));
	if((known_val = ft_lstnew(&val, sizeof(typeof(val)))))
	{
		ft_lstadd(&g_ps.known_vals, known_val);
		return (known_val->content);
	}
	else
		g_ps.errored++;
	return (0);
}

void const	*vaarg_voidptr(va_list *p_va_l)
{
	t_list		*known_val;
	void		*val;

	val = va_arg(*p_va_l, typeof(val));
	if((known_val = ft_lstnew(&val, sizeof(typeof(val)))))
	{
		ft_lstadd(&g_ps.known_vals, known_val);
		return (known_val->content);
	}
	else
		g_ps.errored++;
	return (0);
}

void const	*vaarg_wchar_t(va_list *p_va_l)
{
	t_list		*known_val;
	wchar_t		val;

	val = va_arg(*p_va_l, typeof(val));
	if((known_val = ft_lstnew(&val, sizeof(typeof(val)))))
	{
		ft_lstadd(&g_ps.known_vals, known_val);
		return (known_val->content);
	}
	else
		g_ps.errored++;
	return (0);
}
