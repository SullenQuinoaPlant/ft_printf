#include "ft_printf_inner.h"

void const	*vaarg_shortptr(va_list *p_va_l)
{
	void const	*p_ret;

	p_ret = &va_arg(*p_va_l, short *);
	return (p_ret);
}

void const	*vaarg_size_t(va_list *p_va_l)
{
	void const	*p_ret;

	p_ret = &va_arg(*p_va_l, size_t);
	return (p_ret);
}

void const	*vaarg_ssize_t(va_list *p_va_l)
{
	void const	*p_ret;

	p_ret = &va_arg(*p_va_l, ssize_t);
	return (p_ret);
}

void const	*vaarg_voidptr(va_list *p_va_l)
{
	void const	*p_ret;

	p_ret = &va_arg(*p_va_l, void *);
	return (p_ret);
}

void const	*vaarg_wchar_t(va_list *p_va_l)
{
	void const	*p_ret;

	p_ret = &va_arg(*p_va_l, wchar_t);
	return (p_ret);
}
