#ifndef CONVERT_OUTPUTTERS_STUFFS_H
# define  CONVERT_OUTPUTTERS_STUFFS_H

# include "ft_printf_inner.h"

# define A_SYLLABLES 1000
typedef struct	s_convert_a_stuff {
	t_s_pct		*chk;
	t_s_so 		syllables[A_SYLLABLES];
	t_s_dfp		fpd;
	char		prefix[3];
	t_mib		m;
	t_mib		e;
}				t_s_acs;

void	ca_prefix(int, void*);
void	ca_power0(int, void*);
void	ca_separator(int, void*);
void	ca_mantissa(int, void*);
void	ca_exponent(int, void*);

#endif
