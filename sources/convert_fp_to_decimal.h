#ifndef CONVERT_FP_TO_DECIMAL_H
# define CONVERT_FP_TO_DECIMAL_H

# include "floating_point_bit_patterns.h"
# include <math.h>

typedef struct	s_max_min_power_indexes {
	int32_t	max;
	int32_t	min;
}				t_s_mmpi;

typedef struct	s_power_of_ten {
	int			pow10;
	long double	times;
}				t_s_pot;


typedef uint8_t t_slightlybig[sizeof(uint64_t) + 1];

typedef uint8_t	t_base10buf[sizeof(uintmax_t) / 3 + 1];
	

#endif
