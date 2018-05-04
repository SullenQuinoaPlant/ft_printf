#ifndef BIT_PATTERNS_H
# define BIT_PATTERNS_H

# define SIGN_F 0x01
# define INF_F 0x02
# define NAN_F 0x04

# ifdef ARCH_A
typedef union	u_double {
	double	d;
	char	ar[sizeof(double)];
	struct	{
		unsigned long long	mant : 52;
		unsigned long long	exp : 11;
		unsigned long long	sign : 1;
	};
}				t_u_d;

typedef union	u_ldouble {
	long double	ld;
	char		ar[sizeof(long double)];
	struct		{
		unsigned long long	mant : 64;
		unsigned int		exp : 15;
		unsigned int		sign : 1;
	};
}				t_u_ld;
# endif

typedef struct	s_decomposed_floating_point {
	unsigned int		flags;
	unsigned int		exp;
	unsigned long long	mant;
	unsigned long long	aligned_sgfcd;
}				t_s_dfp;
#endif
