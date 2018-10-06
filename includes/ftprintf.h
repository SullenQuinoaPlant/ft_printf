#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>

int	ft_printf(char const *format, ...);
/*
**Change vprintf prototype to accomodate (va_list)s being array or pointers,
**	depending on the implementation.
*/
int	ft_vprintf(char const *format, va_list *variable_arguments);

#endif
