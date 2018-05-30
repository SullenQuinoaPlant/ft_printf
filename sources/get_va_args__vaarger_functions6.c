#include "ft_printf_inner.h"

void const	*vaarg_wchar_tptr(va_list *p_va_l)
{
	void const	*p_ret;

	p_ret = &va_arg(*p_va_l, wchar_t*);
	return (p_ret);
}

void const	*vaarg_wint_t(va_list *p_va_l)
{
	void const	*p_ret;

	p_ret = &va_arg(*p_va_l, wint_t);
	return (p_ret);
}
