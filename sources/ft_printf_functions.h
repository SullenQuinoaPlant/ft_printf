#ifndef FT_PRINTF_FUNCTIONS_H
# define FT_PRINTF_FUNCTIONS_H

char const *
	attempt_all(
		char const *in,
		char const * (*const *f_str)(char const *));

char const *
	attempt_while_progress(
		char const *in,
		char const * (* const *f_str)(char const *));

void
	convert_a(
		t_s_pct *p_chk);

void
	convert_a_big(
		t_s_pct *p_chk);

void
	convert_c(
		t_s_pct *p_chk);

void
	convert_d(
		t_s_pct *p_chk);

void
	convert_e(
		t_s_pct *p_chk);

void
	convert_e_big(
		t_s_pct *p_chk);

void
	convert_f(
		t_s_pct *p_chk);

void
	convert_f_big(
		t_s_pct *p_chk);

void
	convert_g(
		t_s_pct *p_chk);

void
	convert_g_big(
		t_s_pct *p_chk);

void
	convert_i(
		t_s_pct *p_chk);

void
	convert_n(
		t_s_pct *p_chk);

void
	convert_nospec(
		t_s_pct *p_chk);
void
	convert_o(
		t_s_pct *p_chk);

void
	convert_p(
		t_s_pct *p_chk);

void
	convert_s(
		t_s_pct *p_chk);

void
	convert_u(
		t_s_pct *p_chk);

void
	convert_x(
		t_s_pct *p_chk);

void
	convert_x_big(
		t_s_pct *p_chk);

void
	decompose_fpval(
		void const *p_val, t_e_t type, t_s_dfp *p_ret);

void
	free_parse_state_lists(
		t_s_ps *ps);

int
	get_va_args(
		va_list *vaargs);

int
	gos_update(
		ssize_t writ, size_t expected);

t_s_pct	*
	get_p_pct();

void
	output_char_chk(
		t_s_char const * const chk);

int
	output_chunks(
		int fd, t_s_ps *p_parsed);

int
	output_nan_inf(
		t_s_dfp *val, t_s_pct *p_chk);

int
	output_padnbuffer(
		char *buffer, size_t prefix_len,
		size_t len, t_s_pct *p_chk);

void
	output_padnstuff(
		size_t len, t_s_pct *p_chk,
		t_outputter const f[], void *stuff);

void
	output_pct_chk(
		t_s_pct *p_chk);

void
	output_txt_chk(
		t_s_txt const * const chk);

char const *
	parse_convert(
		char const *in);

char const *
	parse_fill_literal_int_dollar(
		char const *in, int * const to_fill);

int
	parse_format_string(
		char const *in);

char const *
	parse_literal_uint(
		char const *in, unsigned int *p_res);

char const *
	parse_percent(
		char const *in);

char const *
	parse_store_int_literal(
		char const *in, int *** const p_res);

char const *
	parse_text(
		char const *in);

char const *
	percent_char(
		char const *in);

char const *
	percent_convert_dollar_arg(
		char const *in);

char const *
	percent_convert_flags(
		char const *in);

char const *
	percent_convert_length_mod(
		char const *in);

char const *
	percent_convert_precision(
		char const *in);

char const *
	percent_convert_specifier(
		char const *in);

char const *
	percent_convert_star(
		char const *in, int ***p_res);

char const *
	percent_convert_width(
		char const *in);

int **
	ps_store_integer(
		int val, int *** const p_res);

t_s_cc
	sign_to_b(
		int sign, t_s_pct *p_chk, char *b);

char const *
	until_progress(
		char const *in,
		char const * (*const *f_str)(char const *));

void const
	*vaarg_char(
		va_list *p_va_l);
void const
	*vaarg_charptr(
		va_list *p_va_l);
void const
	*vaarg_double(
		va_list *p_va_l);
void const
	*vaarg_int(
		va_list *p_va_l);
void const
	*vaarg_intmax_t(
		va_list *p_va_l);
void const
	*vaarg_intptr(
		va_list *p_va_l);
void const
	*vaarg_long(
		va_list *p_va_l);
void const
	*vaarg_longdouble(
		va_list *p_va_l);
void const
	*vaarg_longlong(
		va_list *p_va_l);
void const
	*vaarg_longlongptr(
		va_list *p_va_l);
void const
	*vaarg_longptr(
		va_list *p_va_l);
void const
	*vaarg_notype(
		va_list *p_va_l);
void const
	*vaarg_ptrdiff_t(
		va_list *p_va_l);
void const
	*vaarg_short(
		va_list *p_va_l);
void const
	*vaarg_shortptr(
		va_list *p_va_l);
void const
	*vaarg_size_t(
		va_list *p_va_l);
void const
	*vaarg_ssize_t(
		va_list *p_va_l);
void const
	*vaarg_uchar(
		va_list *p_va_l);
void const
	*vaarg_uint(
		va_list *p_va_l);
void const
	*vaarg_uintmax_t(
		va_list *p_va_l);
void const
	*vaarg_ulong(
		va_list *p_va_l);
void const
	*vaarg_ulonglong(
		va_list *p_va_l);
void const
	*vaarg_ushort(
		va_list *p_va_l);
void const
	*vaarg_voidptr(
		va_list *p_va_l);
void const
	*vaarg_wchar_t(
		va_list *p_va_l);
void const
	*vaarg_wchar_tptr(
		va_list *p_va_l);
void const
	*vaarg_wint_t(
		va_list *p_va_l);

char const *
	while_progress(
		char const *in,
		char const * (*const *f_str)(char const *));

#endif
