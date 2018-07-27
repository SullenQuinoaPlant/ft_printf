#ifndef FT_PRINTF_FUNCTIONS_H
# define FT_PRINTF_FUNCTIONS_H

void
	apstr_grp_props_nooffset(
		size_t grp_sz, char grp_c, t_s_sgd *gd);

void
	apstr_grp_props_offset(
		size_t grp_sz, char grp_c, t_s_sgd *gd);

size_t
	apstr_len_raw(
		size_t len, size_t grp_sz);

size_t
	apstr_len_syls(
		t_s_so * syl, size_t count,
		size_t grp);

int
	apstr_offset(
		size_t len, size_t grp);

size_t
	apstr_only_grp_len(
		t_s_sgd *gd);

int
	apstr_purge_ornot(
		t_s_pct *chk,
		t_s_so *syls, size_t count);

void
	apstrify_zpad(
		size_t grp,
		t_s_so *pad, int *pos);

void
	apstrify_zpad_grp(
		t_s_so *pad, t_s_sgd *grps);

char const *
	attempt_all(
		char const *in,
		char const * (*const *f_str)(char const *));

void
	call_tstuffers(
		t_stuffer *f_str, void *p_stf,
		int *dummy_indexes);

void
	control_filedes(
		int **fd);

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
	convert_unsigned(
		t_s_pct *chk, char const * base);

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

t_e_t
	get_etype(
		t_e_cs specifier, t_e_lm len_mod);

void
	get_fpndfp(
		t_s_arg *g, t_s_fpndfp *ret);

long double
	get_ldouble(
		t_s_arg *vaarg);

t_s_pct	*
	get_p_pct();

int
	get_padlen(
		t_s_pct *chk, size_t len);

void
	gos_set_apstr(
		size_t grp, char c, size_t len);

void
	gos_set_grp(
		t_s_sgd *grp);

t_s_ctl *
	get_tsctl();

int
	gos_update(
		ssize_t writ, size_t expected);

int
	get_va_args(
		va_list *vaargs);

void
	init_output_state(
		int fd);

void
	init_parse_state();

void
	init_syls(
		enum e_sot type, int how_many, t_s_so *ar);

int
	is_apstr(
		t_s_pct *chk);

t_s_pot
	near_low_pot(
		t_s_fpndfp const *num);

void
	noapstr_grp_props(
		t_s_sgd *gd);

int
	out_apstr_syl(
		t_s_so *syl);

int
	out_eat_tspot(
		size_t count, t_s_pot *num);

int
	out_syl_groups(
		t_s_sgd *grp, int count);

int
	output_c(
		size_t yay_much, char ofthis);

int
	output_cc(
		size_t len, char *b);

void
	output_char_chk(
		t_s_char const * const chk);

int
	output_chunks(
		t_s_ps *p_parsed);

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
		t_s_so *this);

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
	parse_control(
		char const *in);

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

t_s_arg *
	req_arg_init();

int
	round_ccsyl(
		size_t at,
		t_s_so *syl,
		char const * base,
		char *overflow);

int
	round_ldouble(
		long double *d, int pow10);

int
	run_output_ctl(
		t_s_ctl *chk);

void
	set_dfp(
		t_s_pct *chk, t_s_dfp *p_ret);

void
	set_pad_syl(
		t_s_pct *chk, int *pad_i,
		t_s_sgd *syl_grps, int count);

t_s_cc
	sign_to_b(
		int sign, t_s_pct *p_chk, char *b);

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
	sylgrps_outlen(
		t_s_sgd grp[], int count);

size_t
	syls_outlen(
		t_s_so *syl, int count, size_t apstr_grp);

int
	trailing_zeros(
		long double d,
		unsigned int skip,
		unsigned int trail);

int
	tsof_out_eat_tspot(
		size_t len, void *arg);

size_t
	tssos_lensum(
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
