#include "ft_printf_inner.h"

static t_e_t const
	g_types[e_cs_sz][e_lm_sz] =
{
	//e_no_specifier
	{e_notype, e_notype, e_notype, e_notype, e_notype, e_notype, e_notype,
		 e_notype, e_notype},
	//e_a
	{e_double, e_double, e_double, e_double, e_double, e_longdouble, e_double,
		e_double, e_double},
	//e_A
	{e_double, e_double, e_double, e_double, e_double, e_longdouble, e_double,
		e_double, e_double},
	//e_c
	{e_uchar, e_uchar, e_uchar, e_wint_t, e_uchar, e_uchar, e_uchar, e_uchar,
		e_uchar},
	//e_d
	{e_int, e_char, e_short, e_long, e_longlong, e_int, e_intmax_t, e_ssize_t,
		e_ptrdiff_t},
	//e_e
	{e_double, e_double, e_double, e_double, e_double, e_longdouble, e_double,
		e_double, e_double},
	//e_E
	{e_double, e_double, e_double, e_double, e_double, e_longdouble, e_double,
		e_double, e_double},
	//e_f
	{e_double, e_double, e_double, e_double, e_double, e_longdouble, e_double,
		e_double, e_double},
	//e_F
	{e_double, e_double, e_double, e_double, e_double, e_longdouble, e_double,
		e_double, e_double},
	//e_g
	{e_double, e_double, e_double, e_double, e_double, e_longdouble, e_double,
		e_double, e_double},
	//e_G
	{e_double, e_double, e_double, e_double, e_double, e_longdouble, e_double,
		e_double, e_double},
	//e_i
	{e_int, e_char, e_short, e_long, e_longlong, e_int, e_intmax_t, e_ssize_t,
		e_ptrdiff_t},
	//e_n
	//	for which the value stored is actually a pointo the type specified by
	//	the length modifier as follows (where defaults are set to int* see doc):
	//		{e_int, e_char, e_short, e_long, e_longlong, e_int,
	//			e_intmax_t, e_size_t, e_ptrdiff_t},
	{e_voidptr, e_voidptr, e_voidptr, e_voidptr, e_voidptr, e_voidptr, e_voidptr,
		e_voidptr, e_voidptr}
	//e_o
	{e_uint, e_uchar, e_ushort, e_ulong, e_ulonglong, e_uint, e_uintmax_t,
		e_size_t, e_ptrdiff_t},
	//e_p
	{e_voidptr, e_voidptr, e_voidptr, e_voidptr, e_voidptr, e_voidptr,
		e_voidptr, e_voidptr, e_voidptr},
	//e_s
	{e_charptr, e_charptr, e_charptr, e_wchar_tptr, e_charptr, e_charptr,
		e_charptr, e_charptr, e_charptr},
	//e_u
	{e_uint, e_uchar, e_ushort, e_ulong, e_ulonglong, e_uint, e_uintmax_t,
		e_size_t, e_ptrdiff_t},
	//e_x
	{e_uint, e_uchar, e_ushort, e_ulong, e_ulonglong, e_uint, e_uintmax_t,
		e_size_t, e_ptrdiff_t},
	//e_X
	{e_uint, e_uchar, e_ushort, e_ulong, e_ulonglong, e_uint, e_uintmax_t,
		e_size_t, e_ptrdiff_t}
};

t_e_t
	get_etype(
		(t_e_cs specifier, t_e_lm len_mod)
{
	return (g_types[specifier][len_mod]);
}
