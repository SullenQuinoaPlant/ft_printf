#ifndef BIT_PATTERNS_H
# define BIT_PATTERNS_H

# define SIGN_F 0x01
# define INF_F 0x02
# define NAN_F 0x04

# ifdef A
typedef union	u_double {
	double	d;
	char	ar[sizeof(double)];
	struct	{
		unsigned long long	mant : 52;
		unsigned long long	exp : 11;
		unsigned long long	sign : 1;
	}		parts;
}				t_u_d;

typedef struct	s_decomposed_floating_point {
	unsigned int		flags;
	unsigned int		exp;
	unsigned long long	mant;
}				t_s_dfp;
# endif
#endif
