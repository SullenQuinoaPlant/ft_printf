#ifndef CONVERT_OUTPUTTERS_STUFFS_H
# define  CONVERT_OUTPUTTERS_STUFFS_H

# include "ft_printf_inner.h"

# define A_SYLLABLES 1000
typedef struct	s_convert_a_stuff {
	int const	indexes[e_oi_sz] = {10, A_SYLLABLES};
	t_s_cc 		syllables[A_SYLLABLES];
	char		s;
	char		zero;
	char		sep;
	t_mib		m;
	t_mib		e;
}				t_s_acs;

#endif
