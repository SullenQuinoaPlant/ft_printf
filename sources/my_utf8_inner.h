#ifndef MY_UTF8_INNER_H
# define MY_UTF8_INNER_H

# include <limits.h>
# include "libft.h"
# include "my_stupidmath.h"

# define CHAR_HBIT (CHAR_BIT - 1)
# define ASCII_MASK (~0 << CHAR_HBIT)
# define UTF8_BITS (CHAR_BIT - 2)
# define UTF8_BMASK (~0 << UTF8_BITS)
# define UTF8_01X ('\1' << CHAR_HBIT)

# define UNICODE_LIM 0x10FFFF

#endif
