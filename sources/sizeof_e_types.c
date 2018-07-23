#ifndef SIZEOF_E_TYPES_H
# define SIZEOF_E_TYPES_H

# include <stdint.h>
# include <wchar.h>
# include <stddef.h>
# include <stdio.h>

size_t	g_etsz[e_types_sz] = {
		0,
		sizeof(char),
		sizeof(unsigned char),
		sizeof(char*),
		sizeof(double),
		sizeof(long double),
		sizeof(int),
		sizeof(unsigned int),
		sizeof(int*),
		sizeof(intmax_t),
		sizeof(uintmax_t),
		sizeof(long),
		sizeof(unsigned long),
		sizeof(long*),
		sizeof(long long),
		sizeof(unsigned long long),
		sizeof(long long*),
		sizeof(ptrdiff_t),
		sizeof(short),
		sizeof(unsigned short),
		sizeof(short*),
		sizeof(size_t),
		sizeof(ssize_t),
		sizeof(void*),
		sizeof(wchar_t),
		sizeof(wchar_t*),
		sizeof(wint_t)
};

#endif
