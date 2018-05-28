#ifndef FUNCTIONS_H
# define FUNCTIONS_H

int						
	get_va_args(
		va_list *vaargs, t_s_ps *parsed);

size_t
	my_lowvaltobuffer(
		uintmax_t val, char const * const basestr,
		char *b_end);

# define NEG_SIGNED 0x00
# define ALL_SIGNED 0x01
# define ABS_SIGNED 0x02
size_t
	my_signedvaltobuffer(
		intmax_t val, char const * const basestr,
		char *b_end, unsigned int sign_flag);

void
	my_super_clean_free(
		void **data, size_t sz);

size_t
	my_valtobuffer(
		uintmax_t val, char const * const basestr,
		char *b_end);

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
