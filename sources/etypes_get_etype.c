/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   etypes_get_etype.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmauvari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 23:16:15 by nmauvari          #+#    #+#             */
/*   Updated: 2018/10/01 22:01:48 by nmauvari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inner.h"

static t_e_t const				g_types[e_cs_sz][e_lm_sz] =
{
	//e_no_specifier
	{e_notype, e_notype, e_notype, e_notype, e_notype, e_notype, e_notype,
		e_notype, e_notype},
	//e_a
	{e_double, e_double, e_double, e_double, e_double, e_longdouble, e_double,
		e_double, e_double},
	//e_biga
	{e_double, e_double, e_double, e_double, e_double, e_longdouble, e_double,
		e_double, e_double},
	//e_b
	//	for which the value stored is actually a pointer to the type specified by
	//	the length modifier as follows (where defaults are set to int*):
	//		{e_int, e_char, e_short, e_long, e_longlong, e_int,
	//			e_intmax_t, e_size_t, e_ptrdiff_t},
	{e_voidptr, e_voidptr, e_voidptr, e_voidptr, e_voidptr, e_voidptr,
		e_voidptr, e_voidptr, e_voidptr},
	//e_bigb
	//	for which the value stored is actually a pointer to the type specified by
	//	the length modifier as follows (where defaults are set to int*):
	//		{e_int, e_char, e_short, e_long, e_longlong, e_int,
	//			e_intmax_t, e_size_t, e_ptrdiff_t},
	{e_voidptr, e_voidptr, e_voidptr, e_voidptr, e_voidptr, e_voidptr,
		e_voidptr, e_voidptr, e_voidptr},
	//e_c
	{e_uchar, e_uchar, e_uchar, e_wint_t, e_uchar, e_uchar, e_uchar, e_uchar,
		e_uchar},
	//e_bigc
	{e_wint_t, e_wint_t, e_wint_t, e_wint_t, e_wint_t, e_wint_t, e_wint_t,
		e_wint_t, e_wint_t},
	//e_d
	{e_int, e_char, e_short, e_long, e_longlong, e_int, e_intmax_t, e_ssize_t,
		e_ptrdiff_t},
	//e_bigd
	{e_long e_long e_long e_long e_long e_long e_long, e_long, e_long},
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
	//e_k
	//	for which the (void*) must point to a (struct tm) from <time.h>
	{e_voidptr, e_voidptr, e_voidptr, e_voidptr, e_voidptr, e_voidptr,
		e_voidptr, e_voidptr, e_voidptr},
	//e_bigk
	//	for which the (void*) must point to a (struct tm) from <time.h>
	{e_voidptr, e_voidptr, e_voidptr, e_voidptr, e_voidptr, e_voidptr,
		e_voidptr, e_voidptr, e_voidptr},
	//e_n
	//	for which the value stored is actually a pointer to the type specified by
	//	the length modifier as follows (where defaults are set to int* see doc):
	//		{e_int, e_char, e_short, e_long, e_longlong, e_int,
	//			e_intmax_t, e_ssize_t, e_ptrdiff_t},
	{e_voidptr, e_voidptr, e_voidptr, e_voidptr, e_voidptr, e_voidptr, e_voidptr,
		e_voidptr, e_voidptr},
	//e_bign
	//	for which the value stored is a pointer to size_t, always.
	{e_voidptr, e_voidptr, e_voidptr, e_voidptr, e_voidptr, e_voidptr, e_voidptr,
		e_voidptr, e_voidptr},
	//e_o
	{e_uint, e_uchar, e_ushort, e_ulong, e_ulonglong, e_uint, e_uintmax_t,
		e_size_t, e_ptrdiff_t},
	//e_bigo
	{e_ulong e_ulong e_ulong e_ulong e_ulong e_ulong e_ulong, e_ulong,
		e_ulong},
	//e_p
	{e_voidptr, e_voidptr, e_voidptr, e_voidptr, e_voidptr, e_voidptr,
		e_voidptr, e_voidptr, e_voidptr},
	//e_bigp
	{e_voidptr, e_voidptr, e_voidptr, e_voidptr, e_voidptr, e_voidptr,
		e_voidptr, e_voidptr, e_voidptr},
	//e_r
	{e_charptr, e_charptr, e_charptr, e_charptr, e_charptr, e_charptr,
		e_charptr, e_charptr, e_charptr},
	//e_bigr
	{e_int, e_int, e_int, e_int, e_int, e_int, e_int, e_int, e_int},
	//e_s
	{e_charptr, e_charptr, e_charptr, e_wchar_tptr, e_charptr, e_charptr,
		e_charptr, e_charptr, e_charptr},
	//e_u
	{e_uint, e_uchar, e_ushort, e_ulong, e_ulonglong, e_uint, e_uintmax_t,
		e_size_t, e_ptrdiff_t},
	//e_bigu
	{e_ulong e_ulong e_ulong e_ulong e_ulong e_ulong e_ulong, e_ulong,
		e_ulong},
	//e_x
	{e_uint, e_uchar, e_ushort, e_ulong, e_ulonglong, e_uint, e_uintmax_t,
		e_size_t, e_ptrdiff_t},
	//e_X
	{e_uint, e_uchar, e_ushort, e_ulong, e_ulonglong, e_uint, e_uintmax_t,
		e_size_t, e_ptrdiff_t}
};

t_e_t							get_etype(
	t_e_cs specifier,
	t_e_lm len_mod)
{
	return (g_types[specifier][len_mod]);
}
