#ifndef FLOATING_POINT_BIT_PATTERNS_H
# define FLOATING_POINT_BIT_PATTERNS_H

# include <stdint.h>

# define SIGN_F 0x01
# define INF_F 0x02
# define NAN_F 0x04
# define OVER_F 0x08
# define DNORM_F 0x10

# define DB_E_BIAS 1023
# define LDB_E_BIAS 16383

# ifdef ARCH_A
typedef union	u_double {
	double	d;
	char	ar[sizeof(double)];
	struct	{
		uint64_t	mant : 52;
		uint64_t	exp : 11;
		uint64_t	sign : 1;
	};
}				t_u_d;

typedef union	u_ldouble {
	long double	ld;
	char		ar[sizeof(long double)];
	struct		{
		uint64_t	mant : 64;
		uint32_t		exp : 15;
		uint32_t		sign : 1;
	};
}				t_u_ld;
# endif

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
