#include "ft_printf.h"

void const	*vaarg_ulonglong(va_list *p_va_l)
{
	void const	*p_ret;

	p_ret = &va_arg(*p_va_l, unsigned long long);
	return (p_ret);
}

void const	*vaarg_longlongptr(va_list *p_va_l)
{
	void const	*p_ret;

	p_ret = &va_arg(*p_va_l, long long *);
	return (p_ret);
}

void const	*vaarg_ptrdiff_t(va_list *p_va_l)
{
	void const	*p_ret;

	p_ret = &va_arg(*p_va_l, ptrdiff_t);
	return (p_ret);
}

void const	*vaarg_short(va_list *p_va_l)
{
	void const	*p_ret;

	p_ret = &va_arg(*p_va_l, int);
	return (p_ret);
}

void const	*vaarg_ushort(va_list *p_va_l)
{
	void const	*p_ret;

	p_ret = &va_arg(*p_va_l, int);
	return (p_ret);
}
