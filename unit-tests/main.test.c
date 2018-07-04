#include "ftprintf.h"

int		main()
{
	double	a;

	a = 456321.456783754;
	ft_printf("a is :%'0198.100e\n", a);
	a = 123e10;
	ft_printf("a is :%e\n", a);
	ft_printf("a is :%'0e\n", a);
	ft_printf("a is :%'#e\n", a);
	ft_printf("a is :%'#0e\n", a);
	ft_printf("a is :%'#0.10e\n", a);
	ft_printf("a is :%'#-.10e\n", a);
	return (0);
}
