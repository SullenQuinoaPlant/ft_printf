#include "inner.h"

void const	*vaarg_shortptr(va_list *p_va_l)
{
	t_list		*known_val;
	short		*val;

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

void const	*vaarg_size_t(va_list *p_va_l)
{
	t_list		*known_val;
	size_t		val;

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

void const	*vaarg_ssize_t(va_list *p_va_l)
{
	t_list		*known_val;
	ssize_t	val;

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

void const	*vaarg_voidptr(va_list *p_va_l)
{
	t_list		*known_val;
	void		*val;

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

void const	*vaarg_wchar_t(va_list *p_va_l)
{
	t_list		*known_val;
	wchar_t		val;

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
