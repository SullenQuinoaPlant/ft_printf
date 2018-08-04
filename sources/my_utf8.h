#ifndef MY_UTF8_H
# define  MY_UTF8_H

# include <limits.h>
# include "libft.h"
# include "libmystupidmath.h"

# define CHAR_HBIT (CHAR_BIT - 1)
# define ASCII_MASK (~0 << CHAR_HBIT)
# define UTF8_BITS (CHAR_BIT - 2)
# define UTF8_BMASK (~0 << UTF8_BITS)
# define UTF8_01X ('\1' << CHAR_HBIT)

/* 4 == 4. But it's portable! (maybe)*/
# define UTF8_TTL_BITS 21
# define UTF8_MAJ_TTL_BITS (UTF8_TTL_BITS + CHAR_HBIT)
# define UTF8_BIT_GRPS (UTF8_MAJ_TTL_BITS / UTF8_BITS)
# define UTF8_LST_GRP (UTF8_TTL_BITS % UTF8_BITS)
# define UTF8_LEAD_PRFX (UTF8_BIT_GRPS + 1)
# define UTF8_LEAD_BITS (UTF8_LST_GRP + UTF8_LEAD_PRFX)
# define UTF8_LEAD (UTF8_LEAD_BITS > CHAR_BIT)
# define UTF8_MAX_CHARS (UTF8_LEAD + UTF8_BIT_GRPS)

int
	as_utf8seq(
		wchar_t val, int char_lim,
		char *put);

size_t
	str_to_utf8(
		wchar_t *str,
		char 	*put,
		size_t 	len);

int
	true_utf8seq(
		wchar_t val, char *put);

#endif
