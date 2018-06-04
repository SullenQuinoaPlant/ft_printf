#ifndef MY_BUFFERS_H
# define MY_BUFFERS_H

# include <stdint.h>
# include "libft.h"

extern char const	g_oct[];
extern char const	g_dec[];
extern char const	g_hex[];
extern char const	g_bhex[];

# define BIGGEST_BASE2 (sizeof(uintmax_t) * 8)
# define BIGGEST_SIGNED BIGGEST_BASE2 + 1
# define BIGGEST_SIGNED_STRING BIGGEST_SIGNED + 1

enum			e_max_buffer_offsets {
	e_mib_offset = BIGGEST_SIGNED_STRING - 1,
	e_cb_offset = 0
};

typedef struct	s_maxint_buffer {
	size_t  len;
	char	b[BIGGEST_SIGNED_STRING];
}				t_s_mib;

typedef enum	e_sign_policy {
	e_neg_sign,
	e_all_sign,
	e_abs_sign
}				t_e_sp;

typedef struct	s_char_buffer {
	unsigned int	len;
	char			b;
}				t_s_cb;

size_t
	my_lowv_tob(
		uintmax_t val,
		char const * const basestr,
		t_s_mib *b);

size_t
	my_lowvaltob(
		uintmax_t val,
		char const * const basestr,
		char *b_end);

size_t
	my_signvaltob(
		intmax_t val,
		char const * const basestr,
		char *b_end,
		t_e_sp sign_f);

size_t
	my_uv_tob(
		uintmax_t val,
		char const * const basestr,
		t_s_mib *b);

size_t
	my_v_tob(
		intmax_t val,
		char const * const basestr,
		t_s_mib *b,
		t_e_sp sign_f);

size_t
	my_valtobuffer(
		uintmax_t val,
		char const * const basestr,
		char *b_end);

#endif
