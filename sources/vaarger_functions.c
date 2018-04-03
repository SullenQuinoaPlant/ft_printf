#include "h.h"

void const	*vaarg_notype(va_list *p_va_l)
{
	return (0);
}

void const	*vaarg_char(va_list *p_va_l)
{
	return (0);
}
	
void const	*vaarg_uchar(va_list *p_va_l)
{
	return (0);
}

void const	*vaarg_charptr(va_list *p_va_l)
{
	void const	*p_ret;

	p_ret = &va_arg(*p_va_l, char*);
	return (p_ret);
}

void const	*vaarg_double(va_list *p_va_l)
{
	void const	*p_ret;

	p_ret = &va_arg(*p_va_l, double);
	return (p_ret);
}

void const	*vaarg_longdouble(va_list *p_va_l)
{
	void const	*p_ret;

	p_ret = &va_arg(*p_va_l, long double);
	return (p_ret);
}

void const	*vaarg_float(va_list *p_va_l)
{
	return (0);
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

void const	*vaarg_longlong(va_list *p_va_l)
{
	void const	*p_ret;

	p_ret = &va_arg(*p_va_l, long long);
	return (p_ret);
}

void const	*vaarg_ulonglong(va_list *p_va_l)
{
	void const	*p_ret;

	p_ret = &va_arg(*p_va_l, unsigned long long);
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
	return (0);
}

void const	*vaarg_ushort(va_list *p_va_l)
{
	return (0);
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
