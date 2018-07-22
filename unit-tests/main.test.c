#include <stdio.h>
#include "ftprintf.h"

int		main()
{
	double	a;

//	printf("e conversion tests:\n\n");
//
//	a = 456321.456783754;
//	ft_printf("a is :%'0198.100e\n", a);
//	a = 123e10;
//	ft_printf("a is :%e\n", a);
//	ft_printf("a is :%'0e\n", a);
//	ft_printf("a is :%'#e\n", a);
//	ft_printf("a is :%'#0e\n", a);
//	ft_printf("a is :%'#0.10e\n", a);
//	ft_printf("a is :%'#-.10e\n", a);

	printf("g conversion tests:\n\n");

	a = 456321.456783754;
	ft_printf("a is :%'0198.100g\n", a);
//	a = 123e10;
//	ft_printf("a is :%g\n", a);
//	ft_printf("a is :%'0g\n", a);
//	ft_printf("a is :%'#g\n", a);
//	ft_printf("a is :%'#0g\n", a);
//	ft_printf("a is :%'#0.10g\n", a);
//	ft_printf("a is :%'#-.10g\n", a);
	return (0);
}
