#include "ft_printf.h"

void const	*vaarg_longdouble(va_list *p_va_l)
{
	void const	*p_ret;

	p_ret = &va_arg(*p_va_l, long double);
	return (p_ret);
}

void const	*vaarg_int(va_list *p_va_l)
{
	void const	*p_ret;

	p_ret = &va_arg(*p_va_l, int);
	return (p_ret);
}

void const	*vaarg_uint(va_list *p_va_l)
{
	void const	*p_ret;

	p_ret = &va_arg(*p_va_l, unsigned int);
	return (p_ret);
}

void const	*vaarg_intptr(va_list *p_va_l)
{
	void const =p_ret;

	p_ret = &va_arg(*p_va_l, int*);
	return (p_ret);
}

void const	*vaarg_intmax_t(va_list *p_va_l)
{
	void const	*p_ret;

	p_ret = &va_arg(*p_va_l, intmax_t);
	return (p_ret);
}
