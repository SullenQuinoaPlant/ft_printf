#ifndef CONVERT_OUTPUTTERS_STUFFS_H
# define  CONVERT_OUTPUTTERS_STUFFS_H

# include "ft_printf_inner.h"

typedef struct	s_a_conversion_stuff {
	t_s_cb	s;
	char	zero;
	char	sep;
	t_s_mib	m;
	t_s_mib	e;
}				t_s_acs;

#endif
