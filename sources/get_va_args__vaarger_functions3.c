#include "ft_printf_inner.h"

void const	*vaarg_uintmax_t(va_list *p_va_l)
{
	void const	*p_ret;

	p_ret = &va_arg(*p_va_l, uintmax_t);
	return (p_ret);
}

void const	*vaarg_long(va_list *p_va_l)
{
	void const	*p_ret;

	p_ret = &va_arg(*p_va_l, long);
	return (p_ret);
}

void const	*vaarg_ulong(va_list *p_va_l)
{
	void const	*p_ret;

	p_ret = &va_arg(*p_va_l, unsigned long);
	return (p_ret);
}

void const	*vaarg_longptr(va_list *p_va_l)
{
	void const	*p_ret;

	p_ret = &va_arg(*p_va_l, long *);
	return (p_ret);
}

void const	*vaarg_longlong(va_list *p_va_l)
{
	void const	*p_ret;

	p_ret = &va_arg(*p_va_l, long long);
	return (p_ret);
}
