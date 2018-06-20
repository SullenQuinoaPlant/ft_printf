#ifndef FT_PRINTF_FUNCTIONS_H
# define FT_PRINTF_FUNCTIONS_H

char const *
	attempt_all(
		char const *in,
		char const * (*const *f_str)(char const *));

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
	dummy_stuffer(
		int i, void *v);

void
	free_parse_state_lists(
		t_s_ps *ps);

t_s_pct	*
	get_p_pct();

int
	get_padlen(
		t_s_pct *chk, size_t len);

int
	gos_update(
		ssize_t writ, size_t expected);

int
	get_va_args(
		va_list *vaargs);

void
	init_syls(
		enum e_sot type, int how_many, t_s_so *ar);

int
	output_c(
		size_t yay_much, char ofthis);

int
	output_cc(
		char *b, size_t len);

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
		char *b, size_t len[], t_s_pct *p_chk);

void
	output_padnstuff(
		size_t len, t_s_pct *p_chk,
		t_outputter const f[], void *stuff);

void
	output_pct_chk(
		t_s_pct *p_chk);

int
	output_syllable(
		t_s_so this);

int
	output_syllables(
		t_s_so *these, int count);

void
	output_txt_chk(
		t_s_txt const * const chk);

int
	outputter_nop(
		t_s_pct *what, void *ever);

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

char const
	*parse_text_strict(
		char const *in);

char const *
	pctl_fallback(
		t_parser const loop_these[],
		t_parser fallback,
		t_pctl pctl, char const *in);

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

int
	round_ccsyl(
		size_t at,
		t_s_so *syl,
		char const * base,
		char *overflow);

void
	set_dfp(
		t_s_pct *chk, t_s_dfp *p_ret);

void
	set_pad_syl(
		t_s_pct *chk, int *pad_i,
		int	syl_count, t_s_so *syl_ar);

t_s_cc
	sign_to_b(
		int sign, t_s_pct *p_chk, char *b);

void
	stuff_stuff(
		t_stuffer *f_str, void *p_stf,
		int *dummy_indexes);

t_s_so
	syl_lowv_tob(
		uintmax_t val,
		int val_sz,
		char const * basestr,
		t_mib *b);

t_s_so
	syl_uv_tob(
		uintmax_t val,
		char const * basestr,
		t_mib *b);

t_s_so
	syl_v_tob(
		intmax_t val,
		char const * basestr,
		t_mib *b,
		t_e_sp sign_f);

size_t
	tssos_outlen(
		t_s_so stack[], int len);

char const *
	until_no_progress(
		char const *in,
		char const * (* const *f_str)(char const *));

char const *
	until_progress(
		char const *in,
		char const * (*const *f_str)(char const *));

/*void const *vaarg_WHATEVER(va_list*); functions*/
# include "get_va_args__vaargers.h"

char const *
	while_progress(
		char const *in,
		char const * (*const *f_str)(char const *));

#endif
