#ifndef CONVERT_FP_TO_DECIMAL_H
# define CONVERT_FP_TO_DECIMAL_H

# define MANT_RES LDB_MANT_PRECISION

typedef struct	s_power_of_ten {
	int			pow10;
	long double	times;
}				t_s_pot;

#endif
