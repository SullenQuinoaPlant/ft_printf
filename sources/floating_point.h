#ifndef FLOATING_POINT_H
# define FLOATING_POINT_H

# include "floating_point_bit_patterns.h"

typedef struct	s_decomposed_floating_point {
	uint32_t	flags;
	int32_t		exp;
	uint64_t	mant;
	uint64_t	aligned;
}				t_s_dfp;

# define MANTISSA_LOG2_RESOLUTION 63
# define MANT_RES MANTISSA_LOG2_RESOLUTION 

void
	decompose_ldouble(
		long double const *p_val, t_s_dfp *p_ret);

void
	decompose_double(
		double const *p_val, t_s_dfp *p_ret);

long double
	compose_float(
		char sign, uint64_t times, int32_t power);

#endif
