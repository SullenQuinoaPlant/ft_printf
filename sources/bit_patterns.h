#ifndef BIT_PATTERNS_H
# define BIT_PATTERNS_H

# ifdef A
typedef union	u_double {
	double	d;
	char	ar[sizeof(double)];
	struct	{
		unsigned long long	sign : 1;
		unsigned long long	exponent : 11;
		unsigned long long	mantissa : 52;
	}		parts;
}				t_u_d;
# elif defined B
typedef union	u_double {
	double	d;
	char	ar[sizeof(double)];
	struct	{
		unsigned long long	mantissa : 52;
		unsigned long long	exponent : 11;
		unsigned long long	sign : 1;
	}		parts;
}				t_u_d;
# endif
#endif
