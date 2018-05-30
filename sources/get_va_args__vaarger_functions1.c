#include "ft_printf_inner.h"

void const	*vaarg_notype(va_list *p_va_l)
{
	return (0);
}

void const	*vaarg_char(va_list *p_va_l)
{
	void const	*p_ret;

	p_ret = &va_arg(*p_va_l, int);
	return (p_ret);
}
	
void const	*vaarg_uchar(va_list *p_va_l)
{
	void const	*p_ret;

	p_ret = &va_arg(*p_va_l, int);
	return (p_ret);
}

void const	*vaarg_charptr(va_list *p_va_l)
{
	void const	*p_ret;

	p_ret = &va_arg(*p_va_l, char *);
	return (p_ret);
}

void const	*vaarg_double(va_list *p_va_l)
{
	void const	*p_ret;

	p_ret = &va_arg(*p_va_l, double);
	return (p_ret);
}
