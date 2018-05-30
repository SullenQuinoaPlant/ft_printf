#ifndef FUNCTIONS_H
# define FUNCTIONS_H

int						
	get_va_args(
		va_list *vaargs, t_s_ps *parsed);

void
	output_char_chk(
		t_s_char const * const chk);

void
	output_padnstuff(
		size_t len, t_s_pct *p_chk,
		t_outputter f[], void *stuff)

void
	output_txt_chk(
		t_s_txt const * const chk);

int
	register_status(
		ssize_t writ, size_t expected);

int
	sign_to_b(
		int sign, t_s_pct *p_chk, t_s_cb *b);

void const	*vaarg_char(va_list *p_va_l);
void const	*vaarg_charptr(va_list *p_va_l);
void const	*vaarg_double(va_list *p_va_l);
void const	*vaarg_int(va_list *p_va_l);
void const	*vaarg_intmax_t(va_list *p_va_l);
void const	*vaarg_intptr(va_list *p_va_l);
void const	*vaarg_long(va_list *p_va_l);
void const	*vaarg_longdouble(va_list *p_va_l);
void const	*vaarg_longlong(va_list *p_va_l);
void const	*vaarg_longlongptr(va_list *p_va_l);
void const	*vaarg_longptr(va_list *p_va_l);
void const	*vaarg_notype(va_list *p_va_l);
void const	*vaarg_ptrdiff_t(va_list *p_va_l);
void const	*vaarg_short(va_list *p_va_l);
void const	*vaarg_shortptr(va_list *p_va_l);
void const	*vaarg_size_t(va_list *p_va_l);
void const	*vaarg_ssize_t(va_list *p_va_l);
void const	*vaarg_uchar(va_list *p_va_l);
void const	*vaarg_uint(va_list *p_va_l);
void const	*vaarg_uintmax_t(va_list *p_va_l);
void const	*vaarg_ulong(va_list *p_va_l);
void const	*vaarg_ulonglong(va_list *p_va_l);
void const	*vaarg_ushort(va_list *p_va_l);
void const	*vaarg_voidptr(va_list *p_va_l);
void const	*vaarg_wchar_t(va_list *p_va_l);
void const	*vaarg_wchar_tptr(va_list *p_va_l);
void const	*vaarg_wint_t(va_list *p_va_l);

#endif
