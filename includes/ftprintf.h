#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>

typedef struct	s_va_list
{
	va_list		l;
}				t_s_vl;

int	ft_printf(char const *, ...);
int	ft_vprintf(char const *, t_s_vl);

#endif
