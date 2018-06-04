#include "ft_printf_inner.h"

static t_e_t const	g_in_types[e_cs_sz][e_lm_sz] =
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
	{e_intptr, e_charptr, e_shortptr, e_longptr, e_longlongptr, e_intptr,
		e_intptr, e_intptr, e_intptr},
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


char		*parse_convert(char const *in)
{
	char		*(* const f_str[])(char const *) = {
				percent_convert_dollar_arg,
				percent_convert_flags,
				percent_convert_width,
				percent_convert_precision,
				percent_convert_length_mod,
				percent_convert_specifier,
				0};
	t_s_pct		const default = {
				NO_FLAGS,
				0,
				0,
				e_no_len,
				e_no_specifier,
				0};
	t_s_cw 		* const cw = ((t_list*)g_ps.chunks.tail)->content;
	t_s_pct		*chk;
	t_list		*p_arg;

	if (! *in)
		return (in);
	if ((p_arg =
		ft_lstnew(&((t_s_arg){e_notype, 0, 0}), sizeof(t_s_arg))) &&
	 	(chk = malloc(sizeof(t_s_pct))))
	{
		*cw = (t_s_cw){e_pct_c, chk};
		ft_lstadd(&g_ps.p_req_args, p_arg);
		*chk = default;
		chk->vaarg = p_arg->content;
		in = attempt_all(in, f_str);
		if (! chk->vaarg->position)
			chk->vaarg->position = (++g_ps.free_arg_count);
		p_chk->vaarg->type = g_in_types[chk->specifier][chk->len_mod];
	}
	else
	{
		if (p_arg)
			my_clean_free(p_arg, sizeof(t_s_arg));
		g_ps.errored++;
	}
	return (in);
}
