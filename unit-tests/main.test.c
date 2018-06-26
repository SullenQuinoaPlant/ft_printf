#include "ftprintf.h"

int		main()
{
	double	a;

	a = 456321.456783754;
	ft_printf("a is :%'0198.100a\n", a);
	return (0);
}
